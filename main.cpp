#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

int Failed(std::string text);

using namespace boost;
namespace fs = boost::filesystem;

class Repo
{
private:
	fs::path _path;

public:
	Repo(fs::directory_entry dir)
	{
		_path = dir.path();
	}

	std::string GetName() const
	{
		auto p =  _path.filename().c_str();
		return p;
	}
};

class Go
{
private:
	std::vector<Repo> _repos;

public:
	Go(fs::path root)
	{
		if (!exists(root))
			return;

		std::vector<fs::directory_entry> contents;
		std::copy(
				fs::directory_iterator(root), fs::directory_iterator(),
				std::back_inserter(contents));

		for (auto entry : contents)
		{
			if (fs::is_directory(entry))
			{
				_repos.emplace_back(Repo(entry));
			}
		}
	}

	const std::vector<Repo> GetRepos() const { return _repos; }
};

int main(int argc, char *argv[])
{
	auto env { std::getenv("WORK_DIR") };
	if (env == 0)
	{
		std::cerr << "WORK_DIR not set\n";
		return 0;
	}

	fs::path root { env };
	if (!exists(root))
	{
		std::cerr << "Couldn't find anything in WORK_DIR='" << root.c_str() << "'\n";
		return -1;
	}

	Go go(root);
	auto repos = go.GetRepos();

	if (argc == 1)
	{
		auto n = 0;
		for (auto repo : repos)
		{
			std::cerr << n++ << ": " << repo.GetName() << std::endl;
		}

		return 0;
	}

	auto repoNum = boost::lexical_cast<int>(argv[1]);
	if (repoNum < 0 || repoNum >= repos.size())
	{
		std::cerr << "Invalid repo number '" << repoNum << "'\n";
		return -1;
	}

	std::cout << repos[repoNum].GetName();

	return 0;
}

