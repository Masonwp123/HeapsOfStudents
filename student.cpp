#include <iostream>
#include <sstream>
#include "student.h"
#include "date.h"
#include "address.h"

Student::Student() {    
    firstName = "none";
    lastName = "none";
    birthday = new Date();
    graduation = new Date();
    address = new Address();
    creditHours = -1;

}

Student::~Student() {
    delete birthday;
    delete graduation;
    delete address;
}

void Student::init(std::string string) {
    sStudent = string;

    std::stringstream ss;

    ss.clear();
    ss.str(sStudent);
    
    //get first and last name for student
    getline(ss, firstName, ','); //TODO: spaces in names and such causes errors when querying
    getline(ss, lastName, ',');

    //get address strings

    std::string street;
    std::string city;
    std::string state;
    std::string zip;

    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, zip, ',');

    address->init(street, city, state, zip);

    //get dates

    std::string sBirthday;
    std::string sGraduation;

    getline(ss, sBirthday, ',');
    getline(ss, sGraduation, ',');

    birthday->init(sBirthday);
    graduation->init(sGraduation);

    //get credit hours

    std::string sCreditHours;

    getline(ss, sCreditHours);

    ss.clear();
    ss.str("");

    //convert credits hours to an int

    ss << sCreditHours;
    ss >> creditHours;
}

void Student::printStudent() {
    std::cout << "--------------------" << std::endl;
    std::cout << getLastFirst() << std::endl;
    std::cout << "Address: ";
    address->printAddress();
    std::cout << "DOB: ";
    birthday->printDate();
    std::cout << "Grad: ";
    graduation->printDate();
    std::cout << "Credits: " << creditHours << std::endl;
}

std::string Student::getLastFirst() {
    std::stringstream ss;
    ss.clear();
    ss << lastName << ", " << firstName;
    return ss.str();
}

std::string Student::getFirstName() {
    return firstName;
}
    
std::string Student::getLastName() {
    return lastName;
}

int Student::getCreditHours() {
    return creditHours;
}