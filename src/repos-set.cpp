#include "go-repo/repos-set.hpp"
//#include "git2.h"

namespace go_repo
{
    RepoSet::RepoSet(const fs::path& root)
    {
        if (!exists(root))
            return;

        using entry = fs::directory_entry;
        using dir_iter = fs::directory_iterator;

        std::vector<entry> contents;

        std::copy(
            dir_iter(root), dir_iter(),
            std::back_inserter(contents));

        for (const auto& dir : contents)
        {
            if (!fs::is_directory(dir))
                continue;

            auto path = fs::path(dir);
            if (std::find_if(dir_iter(path), dir_iter(),
                [](const entry& p) { return p.path().filename() == ".git"; }) == dir_iter())
            {
                continue;
            }

            _repos.emplace_back(dir);
        }
    }
}
