#!/bin/sh

echo Definining $WORK_DIR functions

echo Adding co
co()
{
	# TODO: move to ~/bin, add to PATH
	cmd=~/src/go/build/go
	cmd=~/work/repos/go-repo/build/Debug/go-repo.exe

	if [ -z "$*" ]; then
		$cmd
		return 0
	fi

	tmp=~/tmp
	next=$tmp/next
	cmds=$tmp/cmds

	# stdout is text to display
	# stderr is commands to execute
	eval $cmd $* 1> $next 2> $cmds

	# used to strip out null bytes
	args=$WORK_DIR/`cat $next`
	cd $args
}

export co

