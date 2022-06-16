#include "pbEntry.h"
#include <sstream>

PbEntry::PbEntry(std::string telephoneNumber, std::string name, std::string address) {
    this->name = name;
    this->address = address;
    this->telephoneNumber = telephoneNumber;
}

std::string PbEntry::toString() const {
    std::stringstream s;
    s << "Telephone number " << this->telephoneNumber << std::endl;;
    s << "\tName: " << this->name <<"." << std::endl;
    s << "\tAddress: " << this->address <<"." << std::endl;

    return s.str();
}