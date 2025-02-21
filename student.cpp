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

    //we have 9 data values
    //string, string, string, string, string, string, date, date, int
    
    //get first and last name for student
    getline(ss, firstName, ',');
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
    std::cout << "name: " << firstName << " " << lastName << std::endl;
    address->printAddress();
    graduation->printDate();
    birthday->printDate();
    std::cout << "creditHours: " << creditHours << std::endl;
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