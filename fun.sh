#!/bin/sh

echo Definining $WORK_DIR functions

echo Adding go
go()
{
	# TODO: move to ~/bin, add to PATH
	cmd=~/src/go/build/go

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

	cd $WORK_DIR/`cat $next`
}

