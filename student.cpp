#include <iostream>
#include "student.h"
#include "date.h"
#include "address.h"

Student::Student() {

    //make it obvious when student is not initialized
    
    firstName = "none";
    lastName = "none";
    credits = -1;

}

void Student::init(std::string string) {
    //parse and stuff
}

void Student::printStudent() {
    //print
    std::cout << "name: " << firstName << " " << lastName << std::endl;
    address.printAddress();
    graduation.printDate();
    birthday.printDate();
    std::cout << "credits: " << credits << std::endl;
}