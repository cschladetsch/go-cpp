#pragma once

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "go-repo/repo.hpp"

namespace go_repo
{
    using namespace boost;
    namespace fs = boost::filesystem;

    class RepoSet
    {
    private:
        std::vector<Repo> _repos;

    public:
        explicit RepoSet(const fs::path& root);

        const std::vector<Repo> &GetRepos() const { return _repos; }
    };
}

