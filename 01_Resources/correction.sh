#!/bin/bash

bin=""
reverse_opt=0

# INIT AND PARSING #############################################################

error_vm() 		{ echo "File filler_vm is missing"; }
error_players() { echo "Folder players is missing"; }
error_maps() 	{ echo "Folder maps is missing"; }
error_script() 	{ echo "File filler_check.sh is missing"; }
error_binary() 	{ echo "Binary invalid"; }

print_usage() { echo 'Usage: sh correction.sh -b [your_binary] [ -a ]'; }

error_exit() {
	($1 1>&2)
	exit "${2:-1}"  ## Return a code specified by $2 or 1 by default.
}

check_presence() {
	local err=0
	if [ ! -f "filler_vm" ] ; then
		local err=1
		error_vm
	fi
	if [ ! -d "players" ] ; then
		local err=1
		error_players
	fi
	if [ ! -d "maps" ] ; then
		local err=1
		error_maps
	fi
	if [ ! -f "filler_check.sh" ] ; then
		local err=1
		error_script
	fi
	if [ $err -eq 1 ] ; then
		exit
	fi
}

options_parsing() {
	local OPTIND
	local OPTARG
	while getopts ":b:r" opt; do
		case ${opt} in
			b)	bin=$OPTARG
				;;
			r)	reverse_opt=1
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
	if [ ! -f $bin ] ; then
		error_exit error_binary
	fi
}

init() {
	check_presence
	options_parsing $@
	check_parameters
}

# MAIN #########################################################################

init $@
