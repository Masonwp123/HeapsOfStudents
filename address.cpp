#include <iostream>
#include "address.h"

Address::Address() {    
    street = "none";
    city = "none";
    state = "none";
    zip = "-1";

}

void Address::init(std::string inStreet, std::string inCity, std::string inState, std::string inZip) {
    street = inStreet;
    city = inCity;
    state = inState;
    zip = inZip;
}

void Address::printAddress() {
    std::cout << street << " " << city << " " << state << " " << zip << std::endl;
}