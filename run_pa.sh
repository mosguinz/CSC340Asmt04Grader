./a.out > pa_stdout.txt

#!/bin/zsh
setopt nullglob

g++ -std=c++17 -- *[aA]/*.cpp *[aA]/*.h

./a.out > a.txt
vimdiff -c "set diffopt+=iwhiteall foldlevel=99999" a.txt pa_stdout_1.txt
rm a.txt

./a.out > a.txt
vimdiff -c "set diffopt+=iwhiteall foldlevel=99999" a.txt pa_stdout_2.txt
rm a.txt

rm a.out
