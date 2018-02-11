#!/bin/bash

p1=""
p2=""
games="5"
map=""
correction_opt=0
alternate_opt=0
rslt_file="rslt.txt"
debug_folder="trace"

## TOOLS FUNCTIONS #############################################################

print_title() {
	echo "*************************************" | tee $rslt_file 
	echo "******** FILLER_TEST RESULTS ********" | tee -a $rslt_file
	echo "*************************************" | tee -a $rslt_file
}

print_game_start() {
	echo "\n*** $p1_basename VS $p2_basename - $map_basename ***" | tee -a $rslt_file
}

print_rslt() {
	local winner=`grep won filler.trace`
	local rslt=`grep AGAINST filler.trace`
	echo "$winner - $rslt" | tee -a $rslt_file
}

print_usage() { echo 'Usage: sh filler_check.sh -1 [player] -2 [player] -m [map] [ -g [nb_games] -a ]'; }

error_file() { echo "Valid $1 file needed"; }

error_vm() { echo "File filler_vm is missing"; }

error_exit() {
	($1 1>&2)
	exit "${2:-1}"  ## Return a code specified by $2 or 1 by default.
}

## INIT #########################################################################

check_vm() {
	if [ ! -f "filler_vm" ] ; then
		error_exit error_vm
	fi
}

options_parsing() {
	local OPTIND
	local OPTARG
	while getopts ":1:2:m:g:ac" opt; do
		case ${opt} in
			1)	p1=$OPTARG
				;;
			2)	p2=$OPTARG
				;;
			m)	map=$OPTARG
				;;
			g)	games=$OPTARG
				;;
			a)	alternate_opt=1
				echo 'a'
				;;
			c)	correction_opt=1
				;;
			\?)	error_exit print_usage
				;;
			:)	error_exit print_usage
				;;
		esac
	done
	shift $((OPTIND-1)) #remove options got by getopts. common practice.
}

check_parameters() {
	err=0
	if [ ! -f $map ] || [ -z $map ] ; then
		error_file 'map'
		err=1
	fi
	if [ ! -f $p1 ] || [ -z $p1 ] ; then
		error_file 'player 1'
		err=1
	fi
	if [ ! -f $p2 ] || [ -z $p2 ] ; then
		error_file 'player 2'
		err=1
	fi
	reg='^[0-9]+$'
	if ! [[ $games =~ $reg ]] ; then
		echo "Number of games must be a numeric value"
		err=1
	elif [ $games -gt 100 ] || [ $games -le 0 ]  ; then
		echo "The number of games must be greater than 0 and less than 100"
		err=1
	fi
	if [ $err -eq 1 ] ; then
		echo "on se casse"
		exit
	fi
}

init_basenames() {
	local tmp=${p1##*/}
	p1_basename=${tmp%.filler}
	local tmp=${p2##*/}
	p2_basename=${tmp%.filler}
	map_basename=${map##*/}
}

del_old_files() {
	rm -rf $debug_folder #correction
	rm -rf $rslt_file #correction
}

init() {
	check_vm
	options_parsing $@
	check_parameters
	del_old_files
	init_basenames
}

## DEBUG FILES #################################################################

init_debug_path() {
	debug_path="$debug_folder/$p1_basename-$p2_basename/$map_basename/$1"
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

## MAIN FUNCTIONS ##############################################################

run_games_p1() {
	for i in `seq 1 $games`
	do
		init_debug_path $i
		./filler_vm -f $map -p1 $p1 -p2 $p2 > "$debug_path/game.txt"
		copy_debug
		print_rslt
	done
}

init $@
print_title #correction
print_game_start
run_games_p1 #alt
