#!/bin/bash
for i in {1..28}
   do
        dfs= "scp -r /usr/hadoop   Slave$i.Haoop:/usr/ " 
         echo $dfs
        $dfs
   done
exit 1
