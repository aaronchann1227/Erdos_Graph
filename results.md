# Final Results

After working on this project for several weeks, we have finally reached a conclusion. We set out with the goals to create a graph of mathematicians from a csv file (found at the Erdos Project form Oakland University) and added our new touch of quantifying distance from Erdos based on number of publications in addition to number of collaborators. Our development consisted of four central elements:
- The graph constructor
- Breadth-First search algorithm
- Kruskal's algorithm for minimum spanning tree
- Kobourov's Barycentric method for force-directed graph visualization

This document intends to show that our code is working as intended, as we have spent several hours debugging and tinkering with our algoirthms so that they are both functional and easy to understand. We will also detail our final project with reference to our initial goals, and assess the project's success.

The graph constructor is perhaps the most complicated and most essential algorithm for our project; it is where we take in the whole csv dataset and convert it into our custom vertices and edges.
--more constructor info--

We also included a breadth-first search algorithm, initially as a means to help with the visualization. We chose to go with breadth-first over depth-first because the structure of the Erdos graph is much more suited for a breadth first search. 
--more bfs--

In our initial goals, we had set out to use Dijkstra's algorithm to recover the initial Erdos number of all the mathematicians. However, as we worked on the project we realized we could be creative with the weights of edges, and output a graph where a minimum spanning tree will also include the shortest path from Erdos to every other mathematician.
--More kruskal info--

Lastly, we included a visualization algorithm so that we have a human-readable output. To do this, we adopted Kobourov's Barycentric method for force-directed graph visualization.
--more vis info--

Overall, we felt this project was a good success, and that our code could be applied to a more general situation.