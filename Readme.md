# Go-Repo - Go to Repository ![logo](res/gorepo_logo.jpg)
[![CodeFactor](https://www.codefactor.io/repository/github/cschladetsch/GoRepo/badge)](https://www.codefactor.io/repository/github/cschladetsch/GoRepo)
[![License](https://img.shields.io/github/license/cschladetsch/gorepo.svg?label=License&maxAge=86400)](./LICENSE.txt)
![Release](https://img.shields.io/github/release/cschladetsch/gorepo.svg?label=Release&maxAge=60)

Provides a fast and simple way to move between `git` repositories stored in an environment variable called `WORK_DIR`.

This is all a WIP made for educational purposes at the moment. See my [YoutTube Channel](https://www.youtube.com/sp4m) for details.

## Install Build and Run
Use `CMake`:

```bash
$ mkdir -p build && cd build && cmake ..
```

For ease of use, he `./b` script will build the app (using `CMake`, then `make`), and the `./r` script will build and run the app if the build worked.

## Script Wrapper

Because C/C++ programs cannot change the invoking shell's current directory, invoking the app requires wrapping it in a bash script function. This is temporarily supplied in a bash script called `fun.sh` in the root of the project.

Simply source `fun.sh` in your bootstrap process for your shell at the moment, like in `~/.bashrc`. This adds a bash function called `go` that wraps the C++ based `go-repo` executable.

## Usage
* `go` - show all repos
* `go n` - go to repo number *n*

## TODO
- [x] Port to Windows (git-bash).
- [ ] Add colored output by default
  - [ ] Add `go -nc` to not use color output
- [ ] Add persistence of location within a repo, so when you switch back to it, you do not always start at the root of the repo.
- [ ] Add `.enter` and `.leave` scripts
  - [ ] `.enter` is invoked when entering a new repo (from the root of that repo)
  - [ ] `leave` is invoked when leaving the existing repo (from the root of the current repo)
- [ ] Add `go -` to go to previous location in previous repo (not just previous repo)
- [ ] Add `go -r` to to go to `WORK_DIR`

## Known Bugs

Under `git-bash`, the warning message:

```bash
warning: command substitution: ignored null byte in input
```

Is displayed when changing repos. This seems to be a new "feature" introduced to `git-bash` for windows (which is based on MINGW64). I haven't got a work-around yet.

