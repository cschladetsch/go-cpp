#pragma once

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

namespace go_repo
{
    using namespace boost;
    namespace fs = boost::filesystem;

    class Repo
    {
    private:
        fs::path _path;

    public:
        Repo(const fs::directory_entry& dir)
        {
            _path = dir.path();
        }

        // Get the final name of the path elements.
        //
        // Note that on different systems, path-names can use different character encodings.
        std::string getName() const
        {
            const auto& name = _path.filename();
            auto const len = name.size();
            const auto* const first = name.c_str();
            const std::locale loc("");	// use system default locale

            std::vector<char> buffer(len + 1);
            std::use_facet<std::ctype<wchar_t> >(loc).narrow(first, first + len, '_', &buffer[0]);
            return std::string(buffer.begin(), buffer.end());
        }
    };

    class RepoSet
    {
    private:
        std::vector<Repo> _repos;
        const fs::path& root_;

    public:
        RepoSet(const fs::path& root);
        const std::vector<Repo> getRepos() const { return _repos; }
    };
}

