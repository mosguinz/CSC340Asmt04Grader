#!/bin/zsh
setopt nullglob

rm -f Assignment-04-Code/{Include.h,LinkedBag340.cpp}
cp -- *[aA]/{Include.h,LinkedBag340.cpp} Assignment-04-Code/
g++ -std=c++17 Assignment-04-Code/*.h Assignment-04-Code/*.cpp

run_diff() {
  ./a.out > a.txt
  vimdiff -c "set diffopt+=iwhiteall foldlevel=99999" a.txt pa_stdout_1.txt
  rm a.txt

  ./a.out > a.txt
  vimdiff -c "set diffopt+=iwhiteall foldlevel=99999" a.txt pa_stdout_2.txt
  rm a.txt
}

run_diff

while true; do
  echo "1: Rerun with last outfile"
  echo "2: Recompile and run with student submitted file"
  echo "3: Exit"
  echo -n "Select (1-3): "
  read choice

  case $choice in
    1)
      run_diff
      ;;
    2)
      g++ -std=c++17 -- *[aA]/*.{cpp,h}
      run_diff
      ;;
    3)
      break
      ;;
  esac
done

rm -f a.out a.txt

