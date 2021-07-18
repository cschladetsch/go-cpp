#!/bin/bash 

#echo Definining $WORK_ROOT functions
#echo Adding go

go() {
	tmp=$WORK_ROOT/tmp
	result=$tmp/go-cmds
	cmd=$WORK_ROOT/repos/go-cpp/cmake-build-debug/go-repo

	mkdir -p $tmp

	eval $cmd $* > $result
	source $result
}

export -f go

