
#include "graph.h"
#include "edge.h"
#include <vector>   /*  type vector  */
#include <string>   /*  type string  */
#include <iostream> /*  cout, cerr  */
#include <sstream>  /*  type stringstream to easily concat a result string  */


int main() {
    /*  Example 1: Das. Ist. Das. Haus. Vom. Ni. Ko. Laus. */
//     std::vector<std::string> vertices = {"A", "B", "C", "D", "E"};
//     std::vector<Edge> edges = {
//         {"A", "B", 4}, {"A", "D", 13}, {"A", "E", 7}, {"B", "C", 2},
//         {"B", "D", 4}, {"B", "E", 13}, {"C", "D", 19}, {"D", "E", 2}
//     };
//     Graph g(vertices, edges);
//     g.letTheSalesmanTravel("A");
//     g.printGraph();

    /*  Example 2: Infinity between two vertices */
     //    std::vector<std::string> vertices = {"A", "B", "C", "D", "E"};
     //    std::vector<Edge> edges = {
     //        {"A", "B", 4}, {"A", "D", 2}, {"A", "E", 3}, {"B", "C", 7},
     //        {"B", "D", 4}, {"B", "E", 1}, {"C", "D", 6}, {"D", "E", 5}
     //    };
//     Graph g(vertices, edges);
//     g.insertEdge({"A", "B", 8});
//     g.letTheSalesmanTravel("A");
    
    /*  Example 3: Oh gosh, looks like we are stranded  */
     std::vector<std::string> vertices = {"Bregenz", "Muenchen", "Innsbruck", "Klagenfurt", "Salzburg", "Linz", "Wien", "StPoelten", "Eisenstadt", "Graz"};
	 std::vector<Edge> edges = {
	     {"Bregenz", "Muenchen", 2}, {"Bregenz", "Innsbruck", 2}, {"Innsbruck", "Muenchen", 6}, {"Innsbruck", "Graz", 5}, {"Innsbruck", "Klagenfurt", 4},
	     {"Muenchen", "Salzburg", 5}, {"Salzburg", "Linz", 3}, {"Salzburg", "Klagenfurt", 5}, {"Klagenfurt", "Linz", 4}, {"Klagenfurt", "Wien", 3},
	     {"Linz", "Graz", 3}, {"Linz", "StPoelten", 2}, {"StPoelten", "Wien", 2}, {"Graz", "Wien", 1},{"Graz", "Eisenstadt", 1},{"Wien", "Eisenstadt", 1}
	 };
	 Graph g(vertices, edges);
	 g.letTheSalesmanTravel("Innsbruck");
}
