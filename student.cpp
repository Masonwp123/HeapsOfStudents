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
    std::cout << string << std::endl;
}