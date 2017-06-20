//
//  sgablec_lab08_q2.cpp
//  Lab00
//
//  Created by Spencer Cook on 2016-12-08.
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string firstName;
    string lastName;
    int employeeID;
    double salary;
    void displayInfo();
};

double validateSalary() {
    double salary = 0;
    cout << "Enter employee's salary: ";
    cin >> salary;
    
    while (salary < 0) {
        cout << "Invalid! Enter a positive salary: ";
        cin >> salary;
    }
    
    return salary;
}

int validateID() {
    string id = "";
    cout << "Enter employee's id: ";
    getline(cin, id);
    bool valid = false;
    
    // Loop to id to make sure all entries are numbers
    for (int i = 0; i < id.length(); i++) {
        cout << "Value " << (int)id[i] << endl;
        if (id[i] <= 57 && id[i] >= 48) {
            valid = true;
        } else {
            valid = false;
            i = id.length() + 1;
        }
    }
    
    while (id.length() != 5 || !valid) {
        cout << "Invalid! Please input a 5 digit ID number: ";
        getline(cin, id);
    }
    
    int number = atoi(id.c_str());
    return number;
}

void dataEntry(Employee edb[], int size) {
    
    for (int i = 0; i < size; i++) {
        cin.ignore();
        cout << "Enter first name: ";
        getline(cin, edb[i].firstName);
        cout << "Enter last name: ";
        getline(cin, edb[i].lastName);
        edb[i].employeeID = validateID();
        edb[i].salary = validateSalary();
    }
}

void searchArrayID(Employee &myArray, int sz, int ID) {
    Employee *edb = &myArray; // reference vairables do not use *, just calling them without any functions in front gets the value stored inside, & is what gets its address
    bool found = false;
    
    for (int i = 0; i < sz; i++) {
        if (edb[i].employeeID == ID) { // has been found
            found = true;
            cout << "Found!" << endl;
            cout << edb[i]. firstName << " " << edb[i].lastName << endl;
            cout << "Salary: $" << edb[i].salary << endl;
            cout << "\n";
            i = sz + 1;
        }
    }
    
    if (!found) {
        cout << "Not found!" << endl;
    }
}

void sortArrayLName(Employee myArray[], int sz) {
    for (int i = sz - 1; i < 0; i--) {
        for (int j = 0; j < i; j++) {
            if (myArray[j].lastName[0] > myArray[j+1].lastName[0]) { // swap
                Employee temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            } else if (myArray[i].lastName[0] == myArray[i + 1].lastName[0]) {
                if (myArray[i].lastName[1] > myArray[i + 1].lastName[1]) {
                    Employee temp = myArray[j];
                    myArray[j] = myArray[j+1];
                    myArray[j+1] = temp;
                }
            }
        }
    }
}

void printArray(Employee *myArray, int sz) {
    for (int i = 0; i < sz; i++) {
        cout << "Name: " << myArray[i].firstName << " " << myArray[i].lastName << endl;
        cout << "ID: " << myArray[i].employeeID << endl;
        cout << "Salary: " << myArray[i].salary << endl;
    }
}

void Employee::displayInfo() {
    cout << "YAAA" << endl;
}

int main()
{
    // Variables
    int numberOfEmployees = 0;
    
    // Get number of employees, and create employee list
    cout << "Enter number of employees: ";
    cin >> numberOfEmployees;
    Employee *employees = new Employee[numberOfEmployees];
    
    dataEntry(employees, numberOfEmployees);
    
    int searchID = 0;
    cout << "Enter ID to search for: ";
    cin >> searchID;
    searchArrayID(*employees, numberOfEmployees, searchID);
    
    printArray(employees, numberOfEmployees);
    
}


