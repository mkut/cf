#!/bin/zsh
mkdir -p $2
mv $1 $2
git add $2/$1
git commit -m "$1 $3"
