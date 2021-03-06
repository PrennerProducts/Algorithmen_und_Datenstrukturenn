#include "edge.h"


Edge::Edge(std::string src, std::string dest) {
    this->setSrc(src);
    this->setDest(dest);
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