#include "graph.h"


Graph::Graph() {                                            //  Default Constructor
    this->vertices = std::vector<std::string>(0);           //  Empty Vector for this->vertices
    this->adjacencyMatrix.resize(0, std::vector<int>(0));   //  0x0 Matrix for this->adjacencyMatrix
}

/*  --
    Constructor with params
--  */
Graph::Graph(const std::vector<std::string>& vertices, const std::vector<Edge>& edges) {
    this->vertices = vertices;                                                                  //  definition of this->vertex through parameter vertices (type: std::vector<std::string>)
    this->adjacencyMatrix.resize((int)vertices.size(), std::vector<int>((int)this->vertices.size(), INT_MAX));     //  creation of an NxN Matrix, based on the size of vertices
    for(int i = 0; i < (int)edges.size(); i++) {
        insertEdge(edges[i]);                   //  edges are added one by one, utilizing the insertEdge()-Function
    }
}

/*  --  /
Function to insert a vertex into the Graph;
    - takes one argument of type std::string that represents a vertex
    - returns void
/   --  */
void Graph::insertVertex(const std::string& vertex) {
    if(this->resolveVertex(vertex) != -1) {         /*  --  */
        std::cerr << "Vertex already in Graph!\n";  /*  Calls this->resolveVertex to check if a given vertex is already in the Graph. Returns with an error, if this is the case.   */
        return;                                     /*  --  */
    }
    this->vertices.push_back(vertex);               //  adds a vertetx via the push_back function provided by std::vector
    this->adjacencyMatrix.resize(this->vertices.size(), std::vector<int>(this->vertices.size()));   //  resizes the adjacencyMatrix to the new size
    for(int i = 0; i < this->vertices.size(); i++) {        /*  --  */
        adjacencyMatrix[i].resize(this->vertices.size());   /*  resizes every "sub" vector of the matrix to the new size    */
    }                                                       /*  --  */
}

/*  --  /
Function to delete a vertex from the Graph;
    - takes one argument of type std::string that represents a vertex
    - returns void
/   --  */
void Graph::deleteVertex(const std::string& vertex) {
    int index = this->resolveVertex(vertex);
    if(index == -1) {                               /*  --  */
        std::cerr << "Vertex not found\n";          /*  Calls this->resolveVertex to check if a given vertex is already in the Graph. Returns with an error, if this is the case.   */
        return;                                     /*  --  */
    }
    this->vertices.erase(this->vertices.begin() + index);   //  erases the vertex at position "index" from this->vertices

    this->adjacencyMatrix.erase(this->adjacencyMatrix.begin() + index);             //  erases the entries from the adjacencyMatrix at "column" position "index"
    for(int i = 0; i < this->adjacencyMatrix[0].size(); i ++) {                     /*  --  */
        this->adjacencyMatrix[i].erase(this->adjacencyMatrix[i].begin() + index);   /*  erases the entries from the adjacencyMatrix in every "row" */
    }                                                                               /*  --  */
}


/*  --  /
Function to insert an Edge
    - takes one argument of type Edge that represents an edge
    - returns void
/   --  */
void Graph::insertEdge(const Edge& edge) {
    int col = this->resolveVertex(edge.getSrc());        //  resolves the src of the edge to the index within the adjacencyMatrix
    int row = this->resolveVertex(edge.getDest());       //  resolves the dest of the edge to the index within the adjacencyMatrix
    if(col == -1 || row == -1) {                    /*  --  */
        std::cerr << "Vertex not found!\n";         /*  Calls this->resolveVertex to check if a given vertex is already in the Graph. Returns with an error, if this is the case.   */
        return;                                     /*  --  */
    }

    this->adjacencyMatrix[col][row]= edge.weight;   //  sets the value of the adjacencyMatrix at position [col][row] to the weight of the edge
    this->adjacencyMatrix[row][col]= edge.weight;   //  sets the value of the adjacencyMatrix at position [col][row] to the weight of the edge
}

/*  --  /
Function to delete an Edge
    - takes one argument of type Edge that represents an edge
    - returns void
/   --  */
void Graph::deleteEdge(const Edge& edge) {
    int col = this->resolveVertex(edge.getSrc());        //  resolves the src of the edge to the index within the adjacencyMatrix
    int row = this->resolveVertex(edge.getDest());       //  resolves the dest of the edge to the index within the adjacencyMatrix
    if(col == -1 || row == -1) {                    /*  --  */
        std::cerr << "Vertex not found!\n";         /*  Calls this->resolveVertex to check if a given vertex is already in the Graph. Returns with an error, if this is the case.   */
        return;                                     /*  --  */
    }
    this->adjacencyMatrix[col][row]= 0;             //  sets the value of the adjacencyMatrix at position [col][row] to 0
}

/*  --  /
Function to check whether vertex v2 is adjacent to vertex v1
    - takes one argument of type Edge that represents an edge
    - returns void
/   --  */
bool Graph::adjacent(const std::string& vertex1, const std::string& vertex2) {
    int indexVertex1 = this->resolveVertex(vertex1);
    int indexVertex2 = this->resolveVertex(vertex2);
    if(indexVertex1 == -1 || indexVertex2 == -1) {
        std::cerr << "Vertex not found!\n";
        return false;
    }
    //  As adjacency is an equivalency relation, we need to check for a possible relation in both direction.
    //  This can be achieved by swapping the the position specifications of the adjacencyMatrix (from [indexVertex1][indexVertex2]
    //  to [indexVertex2][indexVertex1]).
    if(this->adjacencyMatrix[indexVertex1][indexVertex2] != 0 || this->adjacencyMatrix[indexVertex2][indexVertex1] != 0) {
        return true;    //  if a connection (in any direction) is found, return true
    } else {
        return false;   //  else, return false
    }
}

/*  --  /
Function that returns an std::vector of std::string representing the neighbouring vertices of the parameter std::string vertex.
Other than adjacent, neighbourhood is a directed relationship, which means that a vertex "A" can be the neighbour of "B", but
this does not automatically imply that "B" is the neighbour of "A".
    - takes one argument of type std::string that represents a vertex
    - returns a std::vector of std::string
/   --  */
std::vector<std::string> Graph::neighbours(const std::string& vertex) {
    int indexVertex = this->resolveVertex(vertex);                          //  resolves the vertex to the index within the adjacencyMatrix
    std::vector<std::string> resVector = {};                                //  initializes an empty std::vetor of std::string
    for(int i = 0; i < this->adjacencyMatrix[indexVertex].size(); i++) {    /*  Loops through all entries of the subvector of adjacencyMatrix[indexVertex] */
        if(this->adjacencyMatrix[indexVertex][i] != 0) {                    /*  and checks if  the entry at position [indexVertex][i] is not 0. */
            resVector.push_back(this->vertices[i]);                         /*  If the condition is fulfilled, add the vertex (name) to the result vector resVector */
        }
    }
    return resVector;
}

/*  --  /
Function that prints the current Graph's adjacencyMatrix.
    - prints the Graph by utilizing std::cout
    - returns void
/   --  */
void Graph::printGraph() {
    std::cout << "--------------------------------------------\n";
    std::cout << "\t\t";
    for(int i = 0; i < this->vertices.size(); i++) {
        std::cout << this->vertices[i] << "\t";
    }
    std::cout << "\n";
    for(int i=0; i < this->vertices.size(); i++) {
        std::cout << this->vertices[i] << "\t-->\t";
        for (int j = 0; j < this->vertices.size(); j++) {
            std::cout << this->adjacencyMatrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "--------------------------------------------\n";
};

/*  --  /
Function that resolves a parameter std::string name and returns it's index within the this->vertices vector;
between vertices of type std::string and the corresponding index (in the adjacencyMatrix) of type int.
    - takes one argument of type std::string that represents a vertex
    - returns an int representing the vertex's index in the adjacencyMatrix;
    - function returns -1 in case the resolution of the name is unsuccessful
/   --  */
int Graph::resolveVertex(const std::string& vertexName) {
    for(int i = 0; i < this->vertices.size(); i++) {
        if(this->vertices[i] == vertexName) {
            return i;
        }
    }
    return -1;
}

/*  Public implementation of the travelling salesman's algorithm
    -   This approach reduces the complexity of use for the programmer, because it encapsulates:
            * the creation of a std::vector filled with booleans,
            * resolving the vertex
            * the handling of potential errors
            * Handling the startingPoint
    - This "convenience" function increases efficiency of use and reduces error-proneness
*/
void Graph::letTheSalesmanTravel(const std::string& vertex) {
    int vertexIndex = this->resolveVertex(vertex);
    if(vertexIndex == -1) {                     //  Error-Handling in case the vertex could not be resolved
        std::cerr << "Vertex not found!\n";
        exit(1);
    }
    std::cout << vertex;                            //  Outputs the first vertex
    std::vector<bool> visited;                      //  declaration...
    visited.resize(this->vertices.size(), false);   //  ...and initialization of the "visited" vector
    visited[vertexIndex] = true;                    //  every entry of visited is false, except the vertex that has been passed to the function
    this->_letTheSalesmanTravel(vertex, visited, vertex);   //  call the private implementation for the travelling salesman's algorithm
}




int* Graph::performDijkstra(const std::string& sourceVertex){
    std::stringstream retString;                        //  stringstream variable to concat output
    int src = this->resolveVertex(sourceVertex);        //  resolve vertexName of sourceVertex to indicies in the matrix
    if(src == -1 ) {                                     /*  --  */
        std::cerr << "Vertex not found!\n";             /*  If src is -1 (not in this->vertices), return function with error warning   */
        return new int(-1);                   /*  --  */
    }
    bool visited[(int)this->vertices.size()];                //  Declare an array of bool with the size of this->vertices.size() to remember which vertices have already been visited
    int* distances = (int*)malloc((int)this->vertices.size() * sizeof(int));            //  Declare an array of int with the size of this->vertices.size() for the distance metrics

    for(int i = 0; i < (int)this->vertices.size(); i++) {
        visited[i] = false;                             //  every entry of visited is set to false
        distances[i] = INT_MAX;                         //  every entry of distances is set to INT_MAX (this is our way of defining the value "INFINITY")
    }

    distances[src] = 0;                                 // sets the distance of the source to 0, as a vertex can not have a distance to itself

    for(int j = 0; j < (int)this->vertices.size(); j++) {
        int u;                                          //  declaration of int u; will represent our "minimum" element
        int minDist = INT_MAX;                          //  set minDist to INT_MAX, so that the following check does not run into an unexpected error with longer distances

        //  Function to get the minimum distance of the vertexes (in distances) that has not been visited yet (indicated by the visited array)
        for(int k = 0; k < (int)this->vertices.size(); k++) {
            if(distances[k] < minDist && visited[k] == false) {     //  compare distance[k] with the current minDist
                minDist = distances[k];                             //  if a new min is found, assign it to minDist
                u = k;                                              //  the index of the min is assigned to u
            }
        }
        visited[u] = true;      //  state that the vertex at the index of min has been visited by setting it to true

        /*  --  */
        /*  The following loop is key for the Djikstra algorithm. It every for every loop pass it checks if a node has been visited (first condition),
            if the minimum distance is INT_MAX ("INFINITY", second condition), if the there is an edge between the two vertices (third condition, as edges
            are represented trough entries at adjacencyMatrix[u][a]) and if the minimal distance + the edge weight is samller than distance at the current
            distance (distances[a], fourth condition). Only if a vertex has NOT been visited, the minimal distance is NOT INT_MAX, there IS an edge between
            the two vertices and the minimal distance + adjacencyMatrix[u][a] IS SMALLER, adjust the distance at position a.
        /  --  */

        for(int a = 0; a < (int)this->vertices.size(); a++) {
            if(visited[a] == false && distances[u] != INT_MAX && this->adjacencyMatrix[u][a] != INT_MAX && distances[u] + this->adjacencyMatrix[u][a] < distances[a]) {
                distances[a] = distances[u] + adjacencyMatrix[u][a];
            }
        }

    }
    return distances;
}




void Graph::_letTheSalesmanTravel(const std::string& vertex, std::vector<bool>& visited, const std::string& startingPoint) {
    std::string nearestNeighbour;

    /*  std::count takes two arguments of type InputIterator, which are returned by both a vector's begin() and end() function and a
        value to compare it to as a third argument. It will then count the occurences of this third argument in a range between the
        first and second argument.
        For further and more detailed information please refer to: https://en.cppreference.com/w/cpp/algorithm/count
    */
    if(std::count(visited.begin(), visited.end(), false) > 0) {             //  if there is a city/vertex that has not been visited yet
        nearestNeighbour = this->getNearestNeighbour(vertex, visited);      //  get the nearest neighbour of the verted
        this->_letTheSalesmanTravel(nearestNeighbour, visited, startingPoint);  //...and then the function calls itself with the nearest neigbhour as vertex; note: starting point remains the same!
    }
    if(std::count(visited.begin(), visited.end(), true) == 0) {
        return;     //  if all cities/vertices are marked as unvisited, return; this only happens after the next if-block has been
        //  ...called at any point within the recusive structure. As you can see in the public implementation "letTheSalesmanTravel"
        //  ...the function is initially called with one "true" value in the vector "visited".
    }
    /*  Note: this if condition can only be fulfilled by the last recursion. This results from the for-loop
        that will set every entry of "visited" to false. Considering the way recursions work, the approach presented
        here ensures that the last visited city/vertex will connect with the initial one and therefore conclude the
        round trip
    */
    if(std::count(visited.begin(), visited.end(), false) == 0) {    //  if all vertices have been visited
        int startIndex = this->resolveVertex(startingPoint);        //  resolve the initial vertex
        int vertexIndex = this->resolveVertex(vertex);              //  ...and the current vertex
        if(startIndex == -1 || vertexIndex == -1) {                 //  Error-handling if either initial or current vertex could not be resolved
            std::cerr << "Vertex not found!\n";
            exit(1);
        }
        std::cout << " -(";
        if(this->adjacencyMatrix[startIndex][vertexIndex] == INT_MAX) {
            std::cout << "INVALID EDGE";
        } else {
            std::cout << this->adjacencyMatrix[startIndex][vertexIndex];
        }
        std::cout << ")-> " << startingPoint << "\n";    // output that connects the current vertex and the starting point again
        for(int i = 0; i < (int)this->vertices.size(); i++) {    //  setting every entry of "visited" to false
            visited[i] = false;
        }
    }

}



/*  Function that finds the nearest neighbour of a given vertex that has not been visited already
    -   It therefore takes a parameter vertex of type string and a vector of booleans to remember which of the vertices have been visited
    -   It returns a vertex of type std::string
    -   The function will terminate the whole program if the vertex (from the param) cannot be resolved!
*/
std::string Graph::getNearestNeighbour(const std::string& vertex, std::vector<bool>& visited) {
    int nearestNeighbour = INT_MAX; //  initialization of the nearestNeighbour as the index in this->vertices
    int distNearest = INT_MAX;      //  initialization of the nearest distance; not completely necessary, it just improves the readability of the code

    int vertexPos = this->resolveVertex(vertex);    //  Error handling in case the vertex could not be found in this->vertices
    if(vertexPos == -1) {
        std::cerr << "Vertex not found!\n";
        exit(1);
    }

    /*  looping through all vertices to find which of these is nearest  */
    for(int i = 0; i < (int)this->vertices.size(); i++) {
        /*  This if condition checks whether the distance between the vertex from the first input param and this->vertices[i]
            fulfills the condition of <= distNearest. If so, it will assign the corresponding values to nearestNeighbour and distNearest.
            It should be noted that it is crucial to compare with "<=" rather than just "<", because only this way it can be ensured that
            there will ALWAYS be a result, as long as at least one vertex has not been visited. Let's say, we landed at a vertex that is not
            connected to any city that has not yet been visited. If we used "<", the result for nearestNeighbour would be INT_MAX, as it has
            been used to initialize the variable nearestNeighbour, as no city would be closer than INT-MAX (this is because the adjacency matrix
            has been altered to previous versions). By utilizing "<=", it now chooses a city within the bounds of this->vertices, even though the distance
            will be INT_MAX
        */
        if(this->adjacencyMatrix[vertexPos][i] <= distNearest && visited[i] == false) {
            nearestNeighbour = i;
            distNearest = this->adjacencyMatrix[vertexPos][i];
        }
    }

    visited[nearestNeighbour] = true; //    mark the nearestVertex as visited

    std::stringstream s;
    std::cout << " -(";
    if(distNearest == INT_MAX) {
        std::cout << "INVALID EDGE";
    } else {
        std::cout << distNearest;
    }
    std::cout << ")-> " << this->vertices[nearestNeighbour];
    //  output
    s << this->vertices[nearestNeighbour];
    return s.str();
}

void Graph::minSpanningTree(std::string &vertex1, std::string &vertex2) {
    int begin = this->resolveVertex(vertex1);
    bool visited[(int)this->vertices.size()];
    int distance[this->vertices.size()];
    int track[this->vertices.size()];

    for(int i = 0; i < (int)this->vertices.size(); i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[begin] = 0;
    for(int n = 0; n < (int)this->vertices.size(); n++){
        int var, shortestDist = INT_MAX;

        for(int m = 0; m < (int)this->vertices.size(); m++){
            if(visited[m] == false && distance[n] != INT_MAX && this->adjacencyMatrix[n][m] != INT_MAX && distance[m] != 0){
                std::cout << "Hello vertex!";

            }
        }
    }
}
