# Go to Git Repository
[![CodeFactor](https://www.codefactor.io/repository/github/cschladetsch/GoRepo/badge)](https://www.codefactor.io/repository/github/cschladetsch/GoRepo)
[![License](https://img.shields.io/github/license/cschladetsch/gorepo.svg?label=License&maxAge=86400)](./LICENSE.txt)
![Release](https://img.shields.io/github/release/cschladetsch/gorepo.svg?label=Release&maxAge=60)

Provides a fast and simple way to move between repositories.

Set the system environment variable `WORK_DIR` to be the folder that contains all your repos.

## Usage
* `go` - show all repos
* `go n` - go to repo number *n*

## TODO
- [ ] Add colorised output
- [ ] Add .enter and .leave scripts
- [ ] Add persistence of location within a repo, so when you switch back to it, you do not always start at the root of the repo.
- [ ] Add `go -` to go to previos repo (not previous directory)



