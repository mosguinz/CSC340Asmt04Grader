#!/bin/zsh
setopt nullglob

#cp *[aA]/{Include.h,LinkedBag340.cpp} Assignment-04-Code/
#g++ -std=c++17 Assignment-04-Code/*.h Assignment-04-Code/*.cpp

g++ -std=c++17 *[aA]/{Include.h,LinkedBag340.cpp} Assignment-04-Code/*.{cpp,h}

./a.out > a.txt
vimdiff -c "set diffopt+=iwhiteall foldlevel=99999" a.txt pa_stdout_1.txt
rm a.txt

./a.out > a.txt
vimdiff -c "set diffopt+=iwhiteall foldlevel=99999" a.txt pa_stdout_2.txt
rm a.txt

rm a.out
