#include <iostream>
#include "address.h"
#include "date.h"

#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

class Student {

    std::string firstName;
    std::string lastName;
    Address address;
    Date birthday;
    Date graduation;
    int credits;

public:

    Student();
    
    void init(std::string string);
    
};

#endif