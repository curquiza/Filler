#!/bin/bash

get_rslt() {
	i=0
	while read -r line
	do
		let "i=i+1"
		if [ $i -eq 2 ]
		then
			winner=$line
		fi
		tmp=$line
	done < filler.trace

	IFS='AGAINST' read -r -a array <<< "$tmp";
	if [ "${array[0]}" -eq "${array[@]: -1:1}" ]
	then
		echo "Equality" >> "RESULTS.txt"
	else
		echo $winner >> "RESULTS.txt"
	fi
}

map=$1
player=$2
if [ -z $3 ]
then
	time=10
else
	time=$3
fi
rm -rf RESULTS.txt
./filler_vm -f maps/map00 -p1 players/carli.filler -p2 ../curquiza.filler
get_rslt
./filler_vm -f maps/map00 -p1 players/carli.filler -p2 ../curquiza.filler
get_rslt
./filler_vm -f maps/map00 -p1 players/champely.filler -p2 players/champely.filler
get_rslt
