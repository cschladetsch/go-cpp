// (C) 2020 christian@schladetsch.com

#include "GoRepo/Repo.hpp"
#include "../modules/libgit2/src/refs.h"

namespace GoRepo {
    Repo::Repo(const fs::directory_entry& dir) {
        _path = dir.path();
        git_repository_open(&_repo, _path.c_str());
    }

    bool Repo::HasChangedFiles() const {
        return false;
    }

    bool Repo::HasNewFiles() const {
        return false;
    }

    std::string Repo::GetStatusString() const {
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
    }

    std::string Repo::GetBranchName() const {
        git_reference *reference = nullptr;
        git_repository_head(&reference, _repo);
        const char *name = nullptr;
        git_branch_name(&name, reference);
        return name;
    }

}  // namespace GoRepo
