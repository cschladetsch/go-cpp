#!/bin/bash -e -c

echo Definining $WORK_ROOT functions

mkdir -p ~/tmp

echo Adding go
go() {
	cmd=$WORK_ROOT/repos/go-cpp/cmake-build-debug/go-repo

	if [ -z "$*" ]; then
		results=$($cmd)
		eval $results
		return 0
	fi

	tmp=~/tmp
	cmds=$tmp/cmds

	# stdout is text to display
	# stderr is commands to execute
	eval $cmd $* 1> $cmds
	source $cmds
}

export -f go

