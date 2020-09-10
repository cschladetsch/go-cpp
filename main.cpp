#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include <stdlib.h>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

int Failed(std::string text);

using namespace boost;
using namespace boost::filesystem;

class Repo
{
private:
	path _path;

public:
	Repo(directory_entry dir)
	{
		_path = dir.path();
	}

	std::string GetName() const
	{
		return _path.stem().c_str();
	}
};

class Go
{
private:
	std::vector<Repo> _repos;

public:
	Go(path root)
	{
		if (!exists(root))
			return;

		std::vector<directory_entry> contents;
		std::copy(
				directory_iterator(root), directory_iterator(),
				std::back_inserter(contents));

		for (auto entry : contents)
		{
			std::cerr << "Found '" << entry << "'\n";

			if (is_directory(entry))
			{
				_repos.emplace_back(Repo(entry));
			}
		}
	}

	const std::vector<Repo> GetRepos() const { return _repos; }
};

int main(int argc, char *argv[])
{
	path root { getenv("WORK_DIR") };
	if (!exists(root))
	{
		std::cerr << "Couldn't find anything in WORK_DIR='" << root.c_str() << "'";
		return -1;
	}

	Go go(root);
	auto repos = go.GetRepos();

	if (argc == 0)
	{
		auto n = 0;
		for (auto repo : repos)
		{
			std::cout << n << ": " << repo.GetName() << std::endl;
		}

		return 0;
	}

	auto repoNum = boost::lexical_cast<int>(argv[1]);
	if (repoNum < 0 || repoNum >= repos.size())
	{
		std::cerr << "Invalid repo number '" << repoNum << "'";
		return -1;
	}

	std::cout << repos[repoNum].GetName();

	return 0;
}

