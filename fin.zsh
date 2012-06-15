#!/bin/zsh
mkdir -p $2
if [ $# -eq 2 ]
then
	mv $1 $2
else
	mv $1 $2/\!$1
fi
git add $2/*$1
if [ $# -eq 2 ]
then
	git commit -m "$1"
else
	git commit -m "$1 $3"
fi
