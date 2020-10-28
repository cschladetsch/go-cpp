#!/bin/sh

echo Definining $WORK_DIR functions

mkdir -p ~/tmp

echo Adding go
go() {
	# TODO: move to ~/bin, add to PATH
	cmd=$WORK_ROOT/repos/go-cpp/cmake-build-debug/go-repo

	if [ -z "$*" ]; then
		results=`$cmd`
		eval $results
		return 0
	fi

	tmp=~/tmp
	next=$tmp/next
	cmds=$tmp/cmds

	# stdout is text to display
	# stderr is commands to execute
	eval $cmd $* 1> $next 2> $cmds

	# used to strip out null bytes
	args=`cat $next`
	echo args=$args
	eval $args
}

export -f go

