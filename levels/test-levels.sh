#!/usr/bin/env bash

if [ $# -ne 1 ]; then
	echo "Usage: $0 <ip>"
	exit 1
fi

IP=$1

function test() {
	local lvl=$1
	if ! [ -d $lvl ]; then
		echo "$lvl does not exist"
		return
	fi
	if ! [ -f $lvl/flag ]; then
		echo "$lvl doesn't have a flag"
		return
	fi
	echo -n "Testing $lvl flag..."
	FLAG=$(cat $lvl/flag)
	local next=$2
	SSHPASS="$FLAG" sshpass -e ssh $next@$IP -p 4242 "exit" >/dev/null 2>&1
	if [ $? -ne 0 ]; then
		echo " KO"
		return
	fi
	echo " OK"
}

for lvl in {0..8}; do
	test "level$lvl" "level$((lvl+1))"
done
test "level9" "bonus0"
for bonus in {0..2}; do
	test "bonus$bonus" "bonus$((bonus+1))"
done
test "bonus3" "end"
