// (C) 2020 christian@schladetsch.com

#include <boost/filesystem.hpp>
#include <iostream>

#include "GoRepo/subprocess.hpp"
#include "GoRepo/Repo.hpp"
//#include "../modules/libgit2/src/refs.h"

namespace fs = boost::filesystem;

namespace GoRepo {
    Repo::Repo(const fs::directory_entry& dir) {
        _path = dir.path();
        //git_repository_open(&_repo, _path.c_str());
    }

    bool Repo::HasChangedFiles() const {
        return false;
    }

    bool Repo::HasNewFiles() const {
        return false;
    }

    std::string Repo::GetStatusString() const {
//        int result = 0;
//        fs::current_path(_path);
//        //std::cout << "Changed to " << fs::current_path() << std::endl;
//
//        const char *cmd[] = {"git", "status", "-s", NULL};
//        //const char *cmd[] = {"pwd", NULL};
//        struct subprocess_s process{};
//        result = subprocess_create(cmd, subprocess_option_inherit_environment, &process);
//        result = subprocess_join(&process, &result);
//        FILE* stdout = subprocess_stdout(&process);
//        char buffer[128]=  {0};
//        char *b = fgets(buffer, 128, stdout);
//        std::cout << "Status output: " << strlen(buffer) << ": " << buffer << std::endl;
//        subprocess_destroy(&process);
//        bool anyOutput = strlen(buffer) > 0;
//        return anyOutput ? "*" : " ";

        /*
        git_status_options opts = GIT_STATUS_OPTIONS_INIT;
        git_status_list *statuses = NULL;
        git_status_list_new(&statuses, _repo, &opts);

        auto count = git_status_list_entrycount(statuses);
        for (auto i = 0; i < count; ++i) {
            const git_status_entry *entry = git_status_byindex(statuses, i);
            if (entry->status == GIT_STATUS_CURRENT)
                continue;

            return "!";
        }

        return "=";
        */
       return "";
    }

    std::string Repo::GetBranchName() const {
        /*
        git_reference *reference = nullptr;
        git_repository_head(&reference, _repo);
        const char *name = nullptr;
        git_branch_name(&name, reference);
        return name;
        */
       return "";
    }

}  // namespace GoRepo
