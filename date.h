#include <iostream>

#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

class Date {

    std::string sDate;
    int month;
    int day;
    int year;

public:

    Date();

    void init(std::string inDate);

    void printDate();

};

#endif