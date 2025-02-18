#include <iostream>

#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

class Address {

    std::string street;
    std::string city;
    std::string state;
    std::string zip;

public:

    Address();

    void init(std::string inStreet, std::string inCity, std::string inState, std::string inZip);

    void printAddress();

};

#endif