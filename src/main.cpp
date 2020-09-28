#include <vector>
#include <iostream>
#include <cstdlib>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "go-repo/repos-set.hpp"

using namespace go_repo;

int main(int argc, char* argv[])
{
	const auto* env{ std::getenv("WORK_DIR") };
	if (env == 0)
	{
		std::cerr << "WORK_DIR not set\n";
		return -1;
	}

	const fs::path root{ env };
	if (!exists(root))
	{
		std::cerr << "Couldn't find anything in WORK_DIR='" << root.c_str() << "'\n";
		return -1;
	}

    	const RepoSet go(root);
	auto repos = go.getRepos();

	if (argc == 1)
	{
		auto n = 0;
		for (auto const &repo : repos)
		{
			std::cerr << n++ << ": " << repo.getName() << std::endl;
		}

		return 0;
	}

    	const auto repoNum = boost::lexical_cast<int>(argv[1]);
	if (repoNum < 0 || repoNum >= repos.size())
	{
		std::cerr << "Invalid repo number '" << repoNum << "'\n";
		return -1;
	}

	std::cout << "cd " << repos[repoNum].getName();

	return 0;
}

