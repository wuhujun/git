CXX := g++ 
CXXFLAGS := -g -Wall
INCLUDE := -I$(HOME)/hadoop/c++/Linux-amd64-64/include
LIBS := -L$(HOME)/hadoop/c++/Linux-amd64-64/lib -lhadooppipes -lhadooputils -lpthread -lcrypto
 
TARGET := wordcount
 
.PHONY: all clean
 
all: $(TARGET) clean
 
wordcount: wordcount.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
 
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDE)
clean:
	rm -f $(TARGET)*.o
