#!/bin/zsh
mkdir -p $2
if [ $# -eq 2 ]
then
	mv *$1 $2/$1
else
	mv *$1 $2
fi
git add .
git commit -m "$1"
