#!/bin/bash

processus=`ps | grep "$1.filler" | grep -v 'ruby' | grep -v 'grep' | cut -d ' ' -f 1`
leaks $processus
