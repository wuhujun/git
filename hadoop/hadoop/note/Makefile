CC = g++
HADOOP_INSTALL = /usr/hadoop
PLATFORM = Linux-amd64-64
CPPFLAGS = -m32 -I$(HADOOP_INSTALL)/c++/$(PLATFORM)/include

wordcount: wordcount.cpp
        $(CC) $(CPPFLAGS) $< -Wall -L$(HADOOP_INSTALL)/c++/$(PLATFORM)/lib -lhadooppipes \
        -lhadooputils -lpthread -g -O2 -o $@
