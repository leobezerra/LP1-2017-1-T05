#!/bin/bash

target=${1#test\/}
fname=$(echo $target | cut -f 2-3 -d "_")

$(diff ../output/$fname.csv $fname.csv > out.diff)
count=$(cat out.diff $output | wc -l)
if [ $count -gt 0 ]; then
  cat out.diff
fi
rm out.diff
