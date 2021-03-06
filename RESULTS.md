# Final Results

After working on this project for several weeks, we have finally reached a conclusion. We set out with the goals to create a graph of mathematicians from a csv file (found at the Erdos Project form Oakland University) and added our new touch of quantifying distance from Erdos based on number of publications in addition to number of collaborators. All of these goals have been met by the devlopment of our code.

Our development consisted of four central elements:
- The graph constructor
- Breadth-First search algorithm
- Kruskal's algorithm for minimum spanning tree
- Kobourov's Barycentric method for force-directed graph visualization

This document intends to show that our code is working as intended, as we have spent several hours debugging and tinkering with our algoirthms so that they are both functional and easy to understand. We will also detail our final project with reference to our initial goals, and assess the project's success.

The graph constructor is perhaps the most complicated and most essential algorithm for our project; it is where we take in the whole csv dataset and convert it into our custom vertices and edges. The output of this contructor is graph with over 13,000 vertices and 20,000 edges that represents every mathematician with Erdos number less or equal to 2.

To test our constructor, we first made sure the number of neighbor of the root is as expected. Second, we randomly chose some of the vertices and made sure that their number of neighbors is matching the expectation. Finally, we picked out some paths in graph and by traversing through adjcent vertices we verified that each vertex has the correct mathematician neighbors.

<img src="https://i.imgur.com/vhz8VVt.png" width="792" height="400">

We also included a breadth-first search algorithm, initially as a means to help with the visualization. We chose to go with breadth-first over depth-first because the structure of the Erdos graph is much more suited for a breadth first search. To test our BFS algorithm, we checked several points. First, we made sure that Erdos was the first node visited, and then we made sure that he was never visited again. Lastly, we checked to make sure that the number of iterations in the BFS was exactly equal to the size of the graph. As our output, we printed the first few names in the traversal.

![Imgur](https://i.imgur.com/Z9xlIlz.png)

In our initial goals, we had set out to use Dijkstra's algorithm to recover the initial Erdos number of all the mathematicians. However, as we worked on the project we realized we could be creative with the weights of edges, and output a graph where a minimum spanning tree will also include the shortest path from Erdos to every other mathematician. This works, as the weight between Erdos and all of his collaborators will all be less or equal to (1/2), and the rest of the weights will be 1. Thus, all of the links leaving Erdos will be included in the MST, and anyone with Erdos number two will directly link to someone with Erdos number 1. Thus everyone in the tree will be linked to Erdos in the minimum number of edges, corresponding to their Erdos number. 

To test the Kruskal Algorithm, we first check that the number of edges it returns is always n-1. Then, we created a couple of small graphs containing around 10 vertices, and we compared the output with our manually calculated Kruskal total weights. Finally, we test it on our complete graph which contains more than 13,000 vertices. We again compare the output with our manually calculated Kruskal total weights and we ended up passing all tests for Kruskal. By testing it this way, we make sure that our Kruskal algorithm not only works on small graph, but it is also able to run at scale. 

<img src="https://i.imgur.com/c3M6bmF.png" width="704" height="450">


Lastly, we included a visualization algorithm so that we have a human-readable output. To do this, we adopted Kobourov's Barycentric method for force-directed graph visualization. The total visualization consists of two algorithms. The first algorithm determines the position of each vertex; The second writes the result to a PNG. To determine the position of each vertex, we randomly assign coordinate to each vertex, and we calculate the attractive repulsive forces between the vertices to land each vertex in the best location. We did not write any test cases but we are confident that our visualization algorithm will correctly display the graph. The output of the visualization can be found in README.md.

The output of main.cpp:

<img src="https://i.imgur.com/Fw7WnmJ.png" width="560" height="860">

<img src="https://i.imgur.com/8o05yf4.png" width="712" height="40">
Overall, we felt this project was a good success, and that our code could be applied to a more general situation. As you can see, all test were passed and you can run them yourself per the instructions in the README.md.


