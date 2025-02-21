# Heaps Of Students; Database Management
Boring... but useful!

## Classes

### **main.cpp**
```
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
    print "Date: " + month + " " + day + " " + year
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
    print "Address: " + street + " " + city + " " + state + " " + zip
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
    print "Name: " + firstName + " " + lastName
    call address.printAddress()
    call birthday.printDate()
    call graduation.printDate()
    print "creditHours: " + creditHours
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