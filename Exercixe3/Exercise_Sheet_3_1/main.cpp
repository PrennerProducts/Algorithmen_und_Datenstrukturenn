
#include "extendedGraph.h"
#include "edge.h"
#include <vector>   /*  type vector  */
#include <string>   /*  type string  */
#include <iostream> /*  cout, cerr  */
#include <sstream>  /*  type stringstream to easily concat a result string  */

int main() {
    /*  Creation of Graph   */
    std::vector<std::string> vertices = {"London", "Mailand", "Wien", "Madrid", "Rom", "Paris", "Amsterdam", "Moskau",
                                         "Berlin", "Lyon"};
    std::vector<Edge> edges = {

            {"London",    "London",    0},
            {"Mailand",   "London",    2},
            {"Wien",      "London",    2},
            {"Madrid",    "London",    0},
            {"London",    "Mailand",   2},
            {"Wien",      "Mailand",   6},
            {"Madrid",    "Mailand",   5},
            {"London",    "Wien",      2},
            {"Mailand",   "Wien",      6},
            {"Rom",       "Wien",      4},
            {"Paris",     "Wien",      5},
            {"Mailand",   "Madrid",    5},
            {"Rom",       "Madrid",    5},
            {"Lyon",      "Madrid",    3},
            {"Wien",      "Rom",       4},
            {"Madrid",    "Rom",       5},
            {"Moskau",    "Rom",       3},
            {"Lyon",      "Rom",       4},
            {"Wien",      "Paris",     5},
            {"Amsterdam", "Paris",     1},
            {"Moskau",    "Paris",     1},
            {"Lyon",      "Paris",     2},
            {"Moskau",    "Amsterdam", 1},
            {"Rom",       "Moskau",    3},
            {"Amsterdam", "Moskau",    1},
            {"Berlin",    "Moskau",    2},
            {"Moskau",    "Berlin",    2},
            {"Lyon",      "Berlin",    2},
            {"Madrid",    "Lyon",      3},
            {"Rom",       "Lyon",      4},
            {"Berlin",    "Lyon",      2},
    };
    Graph g(vertices, edges);
    //g.printGraph();

    g.performDijkstraPath("Amsterdam", "Mailand");

    return 0;
}
