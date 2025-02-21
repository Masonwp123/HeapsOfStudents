#include <iostream>
#include <fstream>
#include "date.h"
#include "address.h"
#include "student.h"

int main(){
  
  //open file
  std::ifstream inFile;
  inFile.open("students.csv");

  //create array of 50 students
  Student* students = new Student[50];

  int counter = 0;

  std::string item;
  while (getline(inFile, item)) {

    students[counter].init(item);
  
    counter++;
  }

  for (int i = 0; i < counter; ++i) {
    students[i].printStudent();
  }

  delete[] students;

  return 0;
} // end main