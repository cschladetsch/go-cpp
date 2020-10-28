// (C) 2020 christian@schladetsch.com

#include <iostream>
#include <cstdlib>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "GoRepo/RepoSet.hpp"

namespace fs = boost::filesystem;

using std::cout;
using std::cerr;
using std::endl;
using std::getenv;

using GoRepo::Repo;
using GoRepo::RepoSet;

int main(int argc, char* argv[]) {
	const auto* env{ getenv("WORK_ROOT") };
	if (env == nullptr) {
		cerr << "$WORK_ROOT not set\n";
		return -1;
	}

	const fs::path root{ env };
	if (!exists(root)) {
		cerr << "$WORK_ROOT='" << root.c_str() << "' doesn't exist.\n";
		return -1;
	}

    git_libgit2_init();

    const RepoSet go(root/"repos");
	auto repos = go.GetRepos();

	if (argc == 1) {
		auto n = 0;
		for (auto const &repo : repos) {
			cout << "echo " << n++ << ": " << repo.GetName();
			cout << endl;
		}

		return 0;
	}

    const auto repoNum = boost::lexical_cast<int>(argv[1]);
	if (repoNum < 0 || repoNum >= repos.size()) {
		cout << "Invalid repo number '" << repoNum << endl;
		return -1;
	}

	fs::path dest = root/"repos"/repos[repoNum].GetName();
	cout << "cd " << dest.c_str() << endl;

	return 0;
}
