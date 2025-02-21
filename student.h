#include <iostream>
#include "address.h"
#include "date.h"

#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

class Student {

    std::string sStudent;
    std::string firstName;
    std::string lastName;
    Address* address;
    Date* birthday;
    Date* graduation;
    int creditHours;

public:

    Student();
    ~Student();
    
    void init(std::string string);

    void printStudent();

    std::string getLastFirst();
    
    std::string getFirstName();
    
    std::string getLastName();

    int getCreditHours();
    
};

#endif