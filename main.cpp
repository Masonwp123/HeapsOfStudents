#include <iostream>
#include "student.h"

int main() {
	std::cout << "Hello World!" << std::endl;
	Student* student = new Student;
	student->sayHi();
	delete student;
	return 0;
}
