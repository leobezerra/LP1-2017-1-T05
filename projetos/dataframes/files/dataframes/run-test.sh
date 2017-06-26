#!/bin/bash

target=${1#test\/}
if [ $target == 't_read_persist' ]; then
  $(diff ../input/turmas20171.csv persist.csv > out.diff)
  count=$(cat out.diff $output | wc -l)
  if [ $count -gt 0 ]; then
    cat out.diff
  fi
  rm out.diff
fi
