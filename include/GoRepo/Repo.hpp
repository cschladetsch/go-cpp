// (C) 2020 christian@schladetsch.com

#pragma once

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

//#include "git2.h"

namespace GoRepo {

namespace fs = boost::filesystem;

class Repo {
private:
    fs::path _path;
    //git_repository *_repo = nullptr;

public:
    explicit Repo(const fs::directory_entry& dir);
    ~Repo() {
        //git_repository_free(_repo);
    }
    Repo &operator=(const Repo &other) {
        _path = other._path;
        return *this;
    }

    friend bool operator<(const Repo& a, const Repo &b) {
        return a._path < b._path;
    }

    bool HasChangedFiles() const;
    bool HasNewFiles() const;

    std::string GetName() const {
        return fs::basename(_path);
    }

    std::string GetStatusString() const;
    std::string GetBranchName() const;
};

}  // namespace GoRepo
