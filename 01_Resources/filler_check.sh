#!/bin/bash

games=$1
player=$2
map=$3
rslt_file="filler_test_rslt.txt"
debug_folder="filler_test_debug"

init() {
	local tmp=${player##*/}
	player_basename=${tmp%.filler}
	map_basename=${map##*/}
	rm -rf $debug_folder #correction
	rm -rf $rslt_file #correction
}

print_title() {
	echo "*************************************" | tee $rslt_file 
	echo "******** FILLER_TEST RESULTS ********" | tee -a $rslt_file
	echo "*************************************" | tee -a $rslt_file
}

print_game_start() {
	echo "\n*** $player_basename - $map_basename ***" | tee -a $rslt_file
}

print_rslt() {
	local winner=`grep won filler.trace`
	local rslt=`grep AGAINST filler.trace`
	echo "$winner - $rslt" | tee -a $rslt_file
}

init_debug_path() {
	debug_path="$debug_folder/$player_basename/$map_basename/$1" #alt
	mkdir -p $debug_path
}

copy_debug() {
	cp filler.trace $debug_path
	if [ -f debug_init ] ; then
		cp debug_init $debug_path #perso
	fi
	if [ -f debug_strat_map ] ; then
		cp debug_strat_map $debug_path #perso
	fi
}

run_games_p1() {
	for i in `seq 1 $games`
	do
		init_debug_path $i
		./filler_vm -f $map -p1 ../curquiza.filler -p2 $player > "$debug_path/game.txt"
		copy_debug
		print_rslt
	done
}

init
print_title #correction
print_game_start
run_games_p1 #alt
