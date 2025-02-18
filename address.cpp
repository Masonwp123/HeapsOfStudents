#include <iostream>
#include "address.h"

Address::Address() {

    //make it obvious when address is not initialized
    
    street = "none";
    city = "none";
    state = "none";
    zip = -1;

}

void Address::init(std::string inStreet, std::string inCity, std::string inState, std::string inZip) {
    //parse and stuff
    std::cout << inStreet << inCity << inState << inZip << std::endl;
}