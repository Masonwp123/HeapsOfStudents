#include <iostream>
#include "address.h"

Address::Address() {    
    street = "none";
    city = "none";
    state = "none";
    zip = "-1";

}

void Address::init(std::string inStreet, std::string inCity, std::string inState, std::string inZip) {
    //parse and stuff
}

void Address::printAddress() {
    //print
    std::cout << "Address: " << street << " " << city << " " << state << " " << zip << std::endl;
}