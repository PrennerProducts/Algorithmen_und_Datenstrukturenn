#include <string>


#pragma once
/*  --  */
//  Class PbEntry consisting of a person's name, his/her address and their telephone number
/*  --  */


class PbEntry {
public:
    std::string name;
    std::string address;
    std::string telephoneNumber;

    PbEntry(std::string telephoneNumber, std::string name, std::string address); //  Constructor with params for easier use
    PbEntry() = delete;

    std::string toString() const;
};