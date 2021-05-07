# Executable Name
EXENAME = Erdos

# Object Types
OBJS = Traversal.o Graph.o main.o DisjointSet.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include Make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

Graph.o: main.cpp Graph.cpp Vertex.h Edge.h DisjointSet.o
	$(CXX) $(CXXFLAGS) main.cpp Graph.cpp

DisjointSet.o: DisjointSet.h 
	$(CXX) $(CXXFLAGS) DisjointSet.cpp

Traversal.o: BFSGraph.cpp Traversal.h
	$(CXX) $(CXXFLAGS) BFSGraph.cpp -o Traversal.o

test: output_msg test.o catch/catchmain.cpp Graph.o Traversal.o DisjointSet.o
	$(LD) -g catch/catchmain.cpp test.o Graph.o Traversal.o DisjointSet.o $(LDFLAGS) -o test

test.o: Tests/test.cpp catch/catch.hpp Vertex.h Edge.h
	$(CXX) $(CXXFLAGS) Tests/test.cpp

clean:
	-rm -f *.o $(EXENAME) test