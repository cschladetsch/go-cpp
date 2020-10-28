// (C) 2020 christian@schladetsch.com

#include <iostream>
#include <cstdlib>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "GoRepo/RepoSet.hpp"

using namespace GoRepo;

int main(int argc, char* argv[]) {
	const auto* env{ std::getenv("WORK_ROOT") };
	if (env == 0) {
		std::cerr << "WORK_ROOT not set\n";
		return -1;
	}

	const fs::path root{ env };
	if (!exists(root)) {
		std::cerr << "WORK_ROOT='" << root.c_str() << "' doesn't exist.\n";
		return -1;
	}

    git_libgit2_init();

    const RepoSet go(root / "repos");
	auto repos = go.GetRepos();

	if (argc == 1) {
		auto n = 0;
		for (auto const &repo : repos) {
			std::cout << "echo " << n++ << ": " << repo.GetName() << std::endl;
		}

		return 0;
	}

    const auto repoNum = boost::lexical_cast<int>(argv[1]);
	if (repoNum < 0 || repoNum >= repos.size()) {
		std::cerr << "Invalid repo number '" << repoNum << "'\n";
		return -1;
	}

	fs::path dest = root/"repos"/repos[repoNum].GetName();
	std::cout << "cd " << dest.c_str() << std::endl;

	return 0;
}
