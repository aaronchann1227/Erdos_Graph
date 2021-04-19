#include <string>
#include <vector>

struct Vertex {
    std::string author;
    std::vector<Edge*> edges;
};

struct Edge {
    double weight;
    Vertex vertex1, vertex2;

};

class ErdosGraph {
    
    public:
    /**
     * Constructor for the Erdos Graph
     */ 
    ErdosGraph(std::vector<std::string> names);

    /**
     * Abstract BFS traversal for the Erdos graph  
     */ 
    void ErdosBFS(Vertex* target) const;

    /**
     * find method that uses dijkstra's algorithm to find a path between two vertices
     */
    std::vector<Edge*> dijkstraFind(const Vertex v1, const Vertex v2) const;
    /**
     * custom printing method for visualizing the path
     */ 
    std::vector<std::string> printPath(std::vector<Edge*> path);
    
    
    
    
    private:

    Vertex* head;

};