// (C) 2020 christian@schladetsch.com

#include "GoRepo/Repo.hpp"

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
}  // namespace GoRepo
