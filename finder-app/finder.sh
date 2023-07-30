#!/bin/sh

#$1 is supposed to be a path to the directory
#$2 is the search str

if [ $# -eq 0 ]
then
    echo "more args"
    exit 1
fi

if [ ! -d "$1" ]
then
    echo "$1 does not existsd"
fi



rsae=$(ls $1 | wc -l)

#grep -r "$2" $1
echo "--------------------------------"
echo "The number of files are ${rsae} and the number of matching lines are "
#grep -c -r "$2" $1*
grep -r "$2" $1* | wc -l

