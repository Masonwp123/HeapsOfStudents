#include <iostream>
#include <sstream>
#include "date.h"

Date::Date() {    
    sDate = "01/01/1970";
    month = 1;
    day = 1;
    year = 1970;
}

void Date::init(std::string inDate) {
    sDate = inDate;

    std::stringstream ss;

    ss.clear();
    ss.str(sDate);

    //get month day and year as strings

    std::string sMonth;
    std::string sDay;
    std::string sYear;

    getline(ss, sMonth, '/');
    getline(ss, sDay, '/');
    getline(ss, sYear, '/');

    //convert each value to integers

    ss.clear();
    ss.str("");

    ss << sMonth;
    ss >> month;

    ss.clear();
    ss.str("");

    ss << sDay;
    ss >> day;

    ss.clear();
    ss.str("");

    ss << sYear;
    ss >> year;
}

void Date::printDate() {
    std::cout << sDate << std::endl;
}