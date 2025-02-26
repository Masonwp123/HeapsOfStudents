# Heaps Of Students; Database Management
Boring... but useful!

## Classes

### **main.cpp**

**main()**
```
function main():
    open file "students.csv" as inFile

    vector<Student> students

    for each line in inFile:
        Student* student = new Student()
        call student.init(line)
        students.add(student)

    call printMenu()
```

**printMenu**
```
function printMenu():
    print "0) quit"
    print "1) print all student names"
    print "2) print all student data"
    print "3) find a student"
    print "4) sort students"

    bool bIsRunning = true
    while bIsRunning:
        print "Please choose 0-3:"

        int selection = get input as int

        switch selection:
            case 0:
                bIsRunning = false
                break
            case 1:
                call printStudentNames(students)
                break
            case 2:
                call printStudents(students)
                break
            case 3:
                call findStudent(students)
                break
            case 4:
                call sortStudents(students)
                break
            default:
                print "invalid input"
                break
```

**printStudents**
```
function printStudents(vector<Student*> students):
    for each student in students:
        call student.printStudent()
```

**printStudentNames**
```
function printStudents(vector<Student*> students):
    for each student in students:
        print call student.getLastFirst()
```

**findStudent**
```
function findStudent(vector<Student*> students):
    string queryName = get string as input

    for each student in students:
        if call student.getFirstLast() == queryName:
            call student.printStudent()
```

**sortByFirstName**
```
function sortByFirstName(Student& s1, Student& s2):
    return call s1.getFirstName() < call s2.getFirstName()
```

**sortByLastName**
```
function sortByLastName(Student& s1, Student& s2):
    return call s1.getLastName() < call s2.getLastName()
```

**sortByCredits**
```
function sortByCredits(Student& s1, Student& s2):
    return call s1.getCreditHours() > call s2.getCreditHours()
```

**sortStudents**
```
function sortStudents(vector<Student*> students):
    print "0) cancel"
    print "1) sort by first name"
    print "2) sort by last name"
    print "3) sort by credit hours"

    bool bIsRunning = true
    while bIsRunning:
        print "Please choose 0-2:"

        int selection = get input as int

        switch selection:
            case 0:
                bIsRunning = false
                break
            case 1:
                call sort(students, sortByFirstName)
                break
            case 2:
                call sort(students, sortByLastName)
                break
            case 3:
                call sort(students, sortByCredits)
                break
            default:
                print "invalid input"
                break
```

### **date.h**
```
class Date:
    -int month
    -int day
    -int year
    
    +Date()
    +void init(string date)
```

### **date.cpp**

**Date()**
```
initialize values to an arbitrary date (january 1st, 1970)
function Date():
    sDate = "01/01/1970"
    month = 1
    day = 1
    year = 1970
```

**init**
```
function init(string inDate):
    sDate = inDate

    string sMonth = first line in inDate using '/' as delimiter
    string sDay = second line in inDate using '/' as delimiter
    string sYear = third line in inDate using '/' as delimiter

    month = sMonth converted to int
    day = sDay converted to int
    year = sYear converted to int
```

**printDate**
```
function printDate():
    print sDate
```

### **address.h**
```
class Address:
    -string street
    -string city
    -string state
    -int zip

    +Address()
    +void init(string street, string city, string state, int zip)
```

### **address.cpp**

**Address()**
```
//initialize everything to none or impossible value
function Address():
    street = "none"
    city = "none"
    state = "none"
    zip = "-1"
```

**init**
```
function init(string inStreet, string inCity, string inState, string inZip):
    street = inStreet
    city = inCity
    state = inState
    zip = inZip
```

**printAddress**
```
function printAddress():
    print street + " " + city + " " + state + " " + zip
```

### **student.h**
```
class Student:
    -string firstName
    -string lastName
    -Address address
    -Date birthday
    -Date graduation
    -int credits

    +Student()
    +void init(string string)
    +string getLastFirst()
    +string getFirstName()
    +string getLastName()
    +int getCreditHours()
```

### **student.cpp**

**Student()**
```
function Student():
    firstName = "none"
    lastName = "none"
    birthday = create date object on heap
    graduation = create date object on heap
    address = create address object on heap
    creditHours = -1
```

**~Student()**
```
function ~Student():
    delete birthday
    delete graduation
    delete address
```

**init**
```
function init(string string):
    sStudent = string

    firstName = first line in string using ',' as delimiter
    lastName = second line in string using ',' as delimiter
    
    string street = third line in string using ',' as delimiter
    string city = fourth line in string using ',' as delimiter
    string state = fifth line in string using ',' as delimiter
    string zip = sixth line in string using ',' as delimiter

    call address.init(street, city, state, zip)

    string sBirthday = seventh line in string using ',' as delimiter
    string sGraduation = eigth line in string using ',' as delimiter

    call birthday.init(sBirthday)
    call graduation.init(sGraduation)

    string sCreditHours = ninth line in string using ',' as delimiter

    creditHours = sCreditHours converted to int
```

**printStudent**
```
function printStudent():
    print lastName + ", " + firstName
    call address.printAddress()
    call birthday.printDate()
    call graduation.printDate()
    print "Credits: " + creditHours
```

**getLastFirst**
```
function getLastFirst():
    return lastName + ", " + firstName;
```

**getFirstName**
```
function getFirstName():
    return firstName
```

**getLastName**
``` 
function getLastName():
    return lastName
```

**getCreditHours**
```
function getCreditHours():
    return creditHours
```