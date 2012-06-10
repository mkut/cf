#!/bin/zsh
if [ "$2" = "cpp" ]
then
	mkdir -p \!$1
	cd \!$1
	template cf.cpp
elif [ "$2" = "hs" ]
then
	mkdir -p \!$1
	cd \!$1
	template cf.hs
elif [ "$2" = "scala" ]
then
	mkdir -p \!$1
	cd \!$1
	template cf.scala
else
	echo "Choose language(cpp/hs/scala)."
fi
