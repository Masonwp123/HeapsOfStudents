#include <iostream>
#include <fstream>
#include <vector>

#include "date.h"
#include "address.h"
#include "student.h"

void sortByName(Student& s1, Student& s2);
void sortByCredits(Student& s1, Student& s2);

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

  //run gui
  std::cout << "0) quit" << std::endl;
  std::cout << "1) print all student names" << std::endl;
  std::cout << "2) print all student data" << std::endl;
  std::cout << "3) find a student" << std::endl;

  bool bIsRunning = true;
  while (bIsRunning) {
    std::cout << std::endl << "please choose 0-3:" << std::endl;
    
    int selection = -1;
    
    std::cin.clear();
    std::cin >> selection;
    
    switch (selection) {
      case 0: 
        bIsRunning = false; 
        break;
      case 1: 
        for (Student*& student : students) {
          std::cout << student->getLastFirst() << std::endl;
        }
        break;
      case 2: 
        for (Student*& student : students) {
          student->printStudent();
        }
        break;
      case 3: {

        std::cout << std::endl << "Enter a last and first name: " << std::endl;

        std::string queryName;

        std::cin.clear();
        std::cin.ignore();
        std::getline(std::cin, queryName);

        for (Student*& student : students) {
          if (student->getLastFirst() == queryName) {
            student->printStudent();
          }
        }
        break;
      }
      default: std::cout << std::endl << "invalid selection" << std::endl; break;
    }
  }

  //delete students
  for (Student*& student : students) {
    delete student;
  }

  return 0;
} // end main