
#include "graph.h"
#include "edge.h"
#include <vector>   /*  type vector  */
#include <string>   /*  type string  */
#include <iostream> /*  cout, cerr  */
#include <sstream>  /*  type stringstream to easily concat a result string  */

int main() {
    /*  Creation of Graph   */
    std::vector<std::string> vertices = {"A", "B", "C", "E", "F", "G"};
    std::vector<Edge> edges = {
        {"A", "B"}, {"A", "G"}, {"B", "E"}, {"B", "C"}, {"B", "E"}, {"C", "F"}, {"E", "F"}, {"E", "G"}
    };
    Graph g(vertices, edges);
    g.printGraph();

    /*  insertVertices  */
    // g.insertVertex("D");
    // g.insertVertex("H");
    // g.printGraph();

    /*  insertEdges */
    // g.insertEdge({"C", "D"});
    // g.insertEdge({"F", "H"});
    // g.insertEdge({"G", "H"});
    // g.insertEdge({"D", "H"});
    // g.printGraph();

    /*  deleteEdges */
    // g.deleteEdge({"D", "H"});
    // g.printGraph();

    /*  Delete Vertices */
    // g.deleteVertex("C");
    // g.printGraph();
    
    /*  Adjacency   */
    // std::cout << "Adjacent B --> A? " << g.adjacent("B", "A") << "\n";
    // std::cout << "Adjacent A --> B? " << g.adjacent("A", "B") << "\n";
    // std::cout << "Adjacent A --> H? " << g.adjacent("A", "H") << "\n";

    /*  Neighbourhood   */
    // std::cout << "\n";
    // std::cout << "Neighbours of B: ";
    // vectorToString(g.neighbours("B"));
    // std::cout << "Neighbours of A: ";
    // vectorToString(g.neighbours("A"));
    // std::cout << "Neighbours of H: ";
    // vectorToString(g.neighbours("H"));
}

void vectorToString(std::vector<std::string> vector) {
    for(int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << "\t";
    }
    std::cout << "\n";
}
