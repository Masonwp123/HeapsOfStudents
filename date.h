#include <iostream>

#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

class Date {

    int month;
    int day;
    int year;

public:

    Date();

    void init(std::string inDate);

};

#endif