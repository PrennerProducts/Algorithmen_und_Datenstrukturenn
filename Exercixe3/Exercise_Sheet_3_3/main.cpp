
#include "graph.h"
#include "edge.h"
#include <vector>   /*  type vector  */
#include <string>   /*  type string  */
#include <iostream> /*  cout, cerr  */
#include <sstream>  /*  type stringstream to easily concat a result string  */

int main() {
    std::vector<std::string> vertices = {"London", "Mailand", "Wien", "Madrid", "Rom", "Paris", "Amsterdam", "Moskau", "Berlin", "Lyon"};
    std::vector<Edge> edges = {
            {"London", "Mailand", 2},
            {"London", "Wien", 2},
            {"Mailand", "Wien", 6},
            {"Mailand", "Madrid", 5},
            {"Wien", "Rom", 4},
            {"Wien", "Paris", 5},
            {"Madrid", "Rom", 5},
            {"Madrid", "Lyon", 3},
            {"Rom", "Moskau", 3},
            {"Rom", "Lyon", 4},
            {"Amsterdam", "Paris", 1},
            {"Amsterdam", "Moskau", 1},
            {"Moskau", "Paris", 1},
            {"Moskau", "Berlin", 2},
            {"Berlin", "Lyon", 2},
            {"Lyon", "Paris", 2}
    };
    Graph mygraph(vertices, edges);
    mygraph.printGraph();

    std:: cout << mygraph.getEdgeWeight("Berlin", "Lyon") << std::endl;
    mygraph.setEdgeWeight("Berlin", "Lyon", 200 );
    std:: cout << mygraph.getEdgeWeight("Berlin", "Lyon") << std::endl;



}
