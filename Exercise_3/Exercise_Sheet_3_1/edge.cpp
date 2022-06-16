#include "edge.h"


Edge::Edge(std::string src, std::string dest, int weight) {
    this->setSrc(src);
    this->setDest(dest);
    this->setWeight(weight);

}

 const std::string& Edge::getSrc() const {
     return this->src;
 }

void Edge::setSrc(std::string src) {
    this->src = src;
}
const std::string& Edge::getDest() const {
    return this->dest;
}
void Edge::setDest(std::string dest) {
    this->dest = dest;
}

int Edge::getWeight() const {
    return this->weight;
}

void Edge::setWeight(int weight) {
    this->weight = weight;
}
