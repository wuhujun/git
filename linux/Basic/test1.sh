#!/bin/bash
echo -n "The Time and the Date is :" 
date 
echo  "Let's see who's login the System"
who
ls1= `ls -l`
echo $ls1
exit 1
