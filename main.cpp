#include <iostream>
#include <fstream>
#include <vector>

#include "date.h"
#include "address.h"
#include "student.h"

int main(){
  
  //open file
  std::ifstream inFile;
  inFile.open("students.csv");

  //create array of students
  std::vector<Student*> students;

  std::string item;
  while (getline(inFile, item)) {

    Student* student = new Student();
    student->init(item);
    students.push_back(student);

  }

  for (Student*& student : students) {
    student->printStudent();
    delete student;
  }

  return 0;
} // end main