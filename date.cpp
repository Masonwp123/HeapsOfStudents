#include <iostream>
#include "date.h"

Date::Date() {

    //default date is January 1st, 1970
    
    month = 1;
    day = 1;
    year = 1970;

}

void Date::init(std::string inDate) {
    //parse and stuff
}

void Date::printDate() {
    //print
    std::cout << "date: " << month << " " << day << " " << year << std::endl;
}