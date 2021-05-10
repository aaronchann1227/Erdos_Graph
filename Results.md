# Final Results

After several weeks of working on this project, we have finally reached a conclusion. When we set out, we wanted to be able to take in a csv file (found at the Oakland University Erdos Project database) and convert it into a graph where we can find the distance from each collaborator to Erdos. While this dataset only included people with Erdos Number less than or equal to two, we still ended up with over 13,000 mathmeticians, and a very complex graph. To help us navigate this graph, we ended up with four total aspects to our development:

- The graph constructor
- Breadth first search
- Kruskal's algorithm for a minimum spanning tree
- Barycentric method for force-directed graph visualization

For each aspect we spent much time verifying that the code worked as intended, and this document intends to show our conclusions from that testing. Lastly, it will enumerate our findings with regards to our original project goals.

The graph constructor was perhaps the most complex and most important part of the code. This is because it is where we were able to read in our csv dataset and convert it into the vertices and edges that we had custom-defined for this project
--more constructor info--

The breadth-first search algorithm was initially intended to be a means of accessing all of the nodes in the graph to help with visualization.
--more bfs info--

While our original project goals had Dijkstra's algorithm as the means of finding a path from a mathematician to Erdos, we settled on Kruskal's algorithm due to the structure of our graph.
--more kruskal info--

Lastly, the visualization was perhaps the most involved algorithm, as we took Kobourov's Barycentric method for force-directed visualization of a graph. This uses mathematics analogous to Hooke's law to help place vertices in space, and then draw edges between them.
--more vis info--

Overall, we feel that this project was a success.
--conclusion--