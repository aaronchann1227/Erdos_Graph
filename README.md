# CS 225 Final Project - Erdos Number
### Contributors: Man Chong Chan, Simon Balisi, Raghavendrea Bhat, (Jerry) Yihan Wu

You can find our presentation here: https://youtu.be/CPbKRIQbzLQ

![Alt Text](ErdosVisualization.gif)

Above gif is the result of our visualization of the our graph using the Barycentric visualization which could be found in http://cs.brown.edu/people/rtamassi/gdhandbook/chapters/force-directed.pdf.


# What is an Erdos Number?

The Erdos number is the number of edges one would need to travel from the mathematician Erdos to another mathematician. Two mathematicians share an edge if they have been co-authors on a paper. Our project explores this concept. We generated a graph using the the dataset from from Oakland University database of coauthors of Erdos (https://oakland.edu/enp/thedata). In addition we traversed the graph using Breadth First Search, generated a Minimal Spanning Tree using Kruskal's algorithm. 

# Project structure

The Graph visualization, construction of the Graph and Minimal Spanning Tree is within `Graph.cpp`.

The BFS Traversal is located in `Traversal.cpp` and `BFSGraph.cpp`.

Information about Vertices and Edges are stored in `Vertex.h` and `Edge.h`, respectively.

Data Processing is done in `ErdosRead.cpp`. We used two CSV files, one of them is `Erdos_Clean.csv` which contains of all of the Erdos 1 and 2 mathematicians. The name of the mathematicians need to be enclosed in quotes and a comma (,) as the delimiter. The first name of each row is a mathematician directly connected to Erdos. The names after the first name in each row are connected to the first. The `Publications.csv` contains information regarding how many publications some mathematicians have with Erdos. 

Our test cases contain test cases that checks the functionality of Kruskal's algorithm, Breadth First Search, and the Graph Construction itself. The test cases are located in `Tests/test.cpp`

# How to run the Project

To see the result of our project in command line, do 

```
make clean
make
```

This should create an executable file called Erdos. You could then run `./Erdos` in your terminal to see the results.

Now, to run the test cases in your terminal, do

```
make test
```

This should create an executable file called test. You could then run `./test` in your terminal to see the result of the test cases.

# Results

In addition to the visualization, our program outputs some sample results from our algorithms.

<img src="https://i.imgur.com/Fw7WnmJ.png" width="560" height="860">

