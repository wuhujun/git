#!/bin/bash
hadoop pipes \
           -D hadoop.pipes.java.recordreader=true \
           -D hadoop.pipes.java.recordwriter=true \
           -input input/Oozie_Introduction \
           -output wordcount-output \
           -program bin/wordcount
