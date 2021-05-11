# Executable Name
EXENAME = Erdos

# Object Types
OBJS = Traversal.o Graph.o main.o DisjointSet.o Animation.o PNG.o HSLAPixel.o lodepng.o 

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O3 -Wall -Wextra -pedantic
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

Graph.o: main.cpp Graph.cpp Vertex.h Edge.h DisjointSet.o Animation.o PNG.o
	$(CXX) $(CXXFLAGS) main.cpp Graph.cpp 

DisjointSet.o: DisjointSet.h 
	$(CXX) $(CXXFLAGS) DisjointSet.cpp

Traversal.o: BFSGraph.cpp Traversal.h
	$(CXX) $(CXXFLAGS) BFSGraph.cpp -o Traversal.o

Animation.o: cs225/PNG.h Animation.h
	$(CXX) $(CXXFLAGS) Animation.cpp

PNG.o: cs225/PNG.h HSLAPixel.o lodepng.o
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o: cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o: cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp	

test: output_msg test.o catch/catchmain.cpp Graph.o Traversal.o DisjointSet.o 
	$(LD) -g catch/catchmain.cpp test.o Graph.o Traversal.o DisjointSet.o PNG.o HSLAPixel.o lodepng.o $(LDFLAGS) -o test

test.o: Tests/test.cpp catch/catch.hpp Vertex.h Edge.h
	$(CXX) $(CXXFLAGS) Tests/test.cpp



clean:
	-rm -f *.o $(EXENAME) test

