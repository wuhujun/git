#!/bin/bash
for i in {1..28}
   do
        dfs= "scp -r /usr/hadoop$i   Slave$i.Haoop:/usr/ " 
        echo $dfs > out.txt 
	dfs
   done
exit 1
