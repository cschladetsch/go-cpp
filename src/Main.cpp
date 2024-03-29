// (C) 2020 christian@schladetsch.com

#include <iostream>
#include <iomanip>
#include <ios>
#include <cstdlib>

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "GoRepo/RepoSet.hpp"
#include "GoRepo/rang.hpp"

namespace fs = boost::filesystem;

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::getenv;

using GoRepo::Repo;
using GoRepo::RepoSet;
using namespace rang;

int main(int argc, char* argv[]) {
    try {
        // TODO(cjs) add a Error(...) function
        const auto* env{ getenv("WORK_ROOT") };
        if (env == nullptr) {
            cout << "$WORK_ROOT not set\n";
            return -1;
        }

        const fs::path root{ env };
        if (!exists(root)) {
            cout << "$WORK_ROOT='" << root.c_str() << "' doesn't exist.\n";
            return -1;
        }

        //git_libgit2_init();

        const RepoSet go(root/"repos");
        auto repos = go.GetRepos();

        if (argc == 1) {
            auto n = 0;

            // TODO: why does this crash?
//            std::sort(repos.begin(), repos.end(), [](Repo const &a, Repo const &b) {
//                return strcmp(a.GetName().c_str(), b.GetName().c_str());
//            });

            for (auto const &repo : repos) {
                string status = repo.GetStatusString();
                string branchName = repo.GetBranchName();

                cout << fg::red << status << ' ' << fg::green << std::setw(2) << std::setfill(' ') << std::right << n++ << ' '
                    << style::bold << fg::blue << std::setw(40) << std::left << std::setfill(' ') << repo.GetName()
                    << fg::reset << fg::gray << style::dim << " @" << branchName << fg::reset << style::reset << endl;
            }

            return 0;
        }

        const auto repoNum = boost::lexical_cast<int>(argv[1]);
        if (repoNum < 0 || repoNum >= repos.size()) {
            cout <<  fg::red << "Error: " << fg::gray << style::dim << "Invalid repo number "
                 << repoNum << endl;
            return -1;
        }

        fs::path dest = root/"repos"/repos[repoNum].GetName();
        cerr << "cd " << dest.c_str() << endl;
    } catch (boost::bad_lexical_cast& e) {
        cout <<  fg::red << "Error: Not a number: " << fg::gray << style::dim << e.what() << endl;
    } catch (std::exception& e) {
        cout <<  fg::red << "Error: " << fg::gray << style::dim << e.what() << endl;
	}

	return 0;
}
