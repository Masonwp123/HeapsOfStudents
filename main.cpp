#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "date.h"
#include "address.h"
#include "student.h"

void printMenu(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void printStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);

void sortStudents(std::vector<Student*>& students);

bool sortByFirstName(Student*& s1, Student*& s2);
bool sortByLastName(Student*& s1, Student*& s2);
bool sortByCredits(Student*& s1, Student*& s2);

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

  //run ui
  printMenu(students);

  //delete students
  for (Student*& student : students) {
    delete student;
  }

  return 0;
}

void printMenu(std::vector<Student*>& students) {

  bool bIsRunning = true;
  while (bIsRunning) {
    std::cout << std::endl;
    std::cout << "0) quit" << std::endl;
    std::cout << "1) print all student names" << std::endl;
    std::cout << "2) print all student data" << std::endl;
    std::cout << "3) find a student" << std::endl;
    std::cout << "4) sort students" << std::endl;

    std::cout << std::endl << "please choose 0-4:" << std::endl;
    
    int selection = -1;
    
    std::cin.clear();
    std::cin >> selection;
    
    switch (selection) {
      case 0: 
        bIsRunning = false; 
        break;
      case 1: 
        printStudentNames(students);
        break;
      case 2: 
        printStudents(students);
        break;
      case 3:
        findStudent(students);
        break;
      case 4:
        sortStudents(students);
        break;
      default: std::cout << std::endl << "invalid selection" << std::endl; break;
    }
  }
}

void printStudents(std::vector<Student*>& students) {
  for (Student*& student : students) {
    student->printStudent();
  }
}

void printStudentNames(std::vector<Student*>& students) {
  for (Student*& student : students) {
    std::cout << student->getLastFirst() << std::endl;
  }
}

void findStudent(std::vector<Student*>& students) {
  std::cout << std::endl << "Enter a last name: " << std::endl;

  std::string queryName;

  std::cin.clear();
  std::cin.ignore();
  std::getline(std::cin, queryName);

  for (Student*& student : students) {
    if (student->getLastName().find(queryName) != std::string::npos) {
      student->printStudent();
    }
  }
}

void sortStudents(std::vector<Student*>& students) {

  bool bIsRunning = true;
  while (bIsRunning) {
    std::cout << std::endl;
    std::cout << "0) back" << std::endl;
    std::cout << "1) sort by first name" << std::endl;
    std::cout << "2) sort by last name" << std::endl;
    std::cout << "3) sort by credits" << std::endl;

    std::cout << std::endl << "please choose 0-3:" << std::endl;
    
    int selection = -1;
    
    std::cin.clear();
    std::cin >> selection;
    
    switch (selection) {
      case 0: 
        bIsRunning = false; 
        break;
      case 1: 
        std::sort(students.begin(), students.end(), sortByFirstName);
        bIsRunning = false; 
        break;
      case 2: 
        std::sort(students.begin(), students.end(), sortByLastName);
        bIsRunning = false; 
        break;
      case 3:
        std::sort(students.begin(), students.end(), sortByCredits);
        bIsRunning = false; 
        break;
      default: std::cout << std::endl << "invalid selection" << std::endl; break;
    }
  }
}

bool sortByFirstName(Student*& s1, Student*& s2) {
  return s1->getFirstName() < s2->getFirstName();
}

bool sortByLastName(Student*& s1, Student*& s2) {
  return s1->getLastName() < s2->getLastName();
}

bool sortByCredits(Student*& s1, Student*& s2) {
  return s1->getCreditHours() > s2->getCreditHours();  
}