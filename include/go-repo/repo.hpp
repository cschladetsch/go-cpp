#pragma once

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

//#include "git2.h"

namespace go_repo
{
    using namespace boost;
    namespace fs = boost::filesystem;

    class Repo
    {
    private:
        fs::path _path;
        //git_repository *_repo = 0;

    public:
        explicit Repo(const fs::directory_entry& dir);

        bool HasChangedFiles() const;
        bool HasNewFiles() const;

        // Get the final name of the path elements.
        std::string GetName() const
        {
            return fs::basename(_path);
        }
    };
}
