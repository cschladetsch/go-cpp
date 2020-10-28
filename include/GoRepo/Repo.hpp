// (C) 2020 christian@schladetsch.com

#pragma once

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "git2.h"

namespace GoRepo {

using namespace boost;
namespace fs = boost::filesystem;

class Repo {
private:
    fs::path _path;
    git_repository *_repo = 0;

public:
    explicit Repo(const fs::directory_entry& dir);

    bool HasChangedFiles() const;
    bool HasNewFiles() const;

    std::string GetName() const {
        return fs::basename(_path);
    }
};

}  // namespace GoRepo
