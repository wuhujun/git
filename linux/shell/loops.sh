#!/bin/bash
for i in {1..10}
do
 echo $i
done

for file in a b c 
do
  echo $file
done

for var in $(ls ./*)
do
  echo $var
done
exit 1
