//
//  sgablec_lab07_q1.cpp
//  Lab00
//
//  Created by Spencer Cook on 2016-11-20.
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>

// Methods
void myHeader(string name, int lab, string date, int question);
void inputGrades(double gradesTable[5][3]);
double getGrade();
void convertToLetter(double gradesTable[5][3], string letterTable[5][3]);
void printTable(string letterTable[5][3]);
double average(double gradesTable[5][3]);
bool verifyChoice();
void myHeader(string name, int number, string date, int question);
void myFooter();

int main()
{
    myHeader("Spencer Gable-Cook", 7, "Tuesday November 22, 2016", 1);
    
    do {
        // Declare and initialize variables
        double gradesTable[5][3];
        string letterGrades[5][3];
        double averageGrade = 0;
        
        // Call methods
        inputGrades(gradesTable);
        convertToLetter(gradesTable, letterGrades);
        printTable(letterGrades);
        
        averageGrade = average(gradesTable);
        cout << "Your average grade is " << averageGrade << "% " << endl;
        
        if (averageGrade >= 50) {
            cout << "Congratulations! You passed the academic year!" << endl;
        } else {
            cout << "Oh no! You failed the academic year!" << endl;
        }
    } while (verifyChoice());
    
    myFooter();
}

void inputGrades(double gradesTable[5][3]) {
    for (int r = 0; r < 5; r++) {
        cout << "Enter the grades of course #" << (r + 1) << "..." << endl;
        for (int c = 0; c < 3; c++) {
            string nameOfAssignment = "";
            if (c == 0) {
                nameOfAssignment = "Assignment";
            } else if (c == 1) {
                nameOfAssignment = "Midterm";
            } else {
                nameOfAssignment = "Final exam";
            }
            
            cout << "Enter grade of " << nameOfAssignment << ": ";
            gradesTable[r][c] = getGrade();
        }
    }
}

double getGrade() {
    string grade;
    int dpcount = 0; //counter for counting number of decimal places
    getline(cin, grade);
    
    for (int i = 0; i < (int)grade.size(); i++) {
        if (grade[i] == '.') {
            dpcount++;
        }
        if (i == 0) {
            if (!((grade[0] == '-') || grade[0] == '.' || (grade[0] >= '0' && grade[0] <= '9'))) {
                cout << "Invalid entry! Please enter a valid number: ";
                getline(cin, grade);
                i = -1;
                dpcount = 0;
            }
        } else if (!((dpcount < 2) && (grade[i] >= '0' && grade[i] <= '9') || grade[i] == '.')) {
            cout << "Invalid entry! Please enter a valid number: ";
            getline(cin, grade);
            i = -1;
            dpcount = 0;
        }
    }
    double finalGrade = atof(grade.c_str());
    
    // Verify number is between 0 and 100
    while (finalGrade < 0 || finalGrade > 100) {
        cout << "Invalid! Enter a mark between 0 and 100: ";
        finalGrade = getGrade();
    }
    
    return finalGrade;
}

void convertToLetter(double gradesTable[5][3], string letterTable[5][3]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 3; c++) {
            if (gradesTable[r][c] >= 95) {
                letterTable[r][c] = "A+";
            } else if (gradesTable[r][c] >= 90) {
                letterTable[r][c] = "A";
            } else if (gradesTable[r][c] >= 85) {
                letterTable[r][c] = "B+";
            } else if (gradesTable[r][c] >= 80) {
                letterTable[r][c] = "B";
            } else if (gradesTable[r][c] >= 70) {
                letterTable[r][c] = "C";
            } else if (gradesTable[r][c] >= 60) {
                letterTable[r][c] = "D";
            } else {
                letterTable[r][c] = "F";
            }
        }
    }
}

void printTable(string letterTable[5][3]) {
    for (int r = 0; r < 5; r++) {
        cout << "\nCourse #" << (r + 1) << ": " << endl;
        for (int c = 0; c < 3; c++) {
            cout << "| " << letterTable[r][c] << " | ";
        }
    }
}

double average(double gradesTable[5][3]) {
    double average[5];
    double total = 0;
    for (int r = 0; r < 5; r++) {
        average[r] = gradesTable[r][0] * 0.15 + gradesTable[r][1] * 0.25 + gradesTable[r][2] * 0.6;
        total += average[r];
    }
    double totalAverage = total / 5;
    return totalAverage;
}

bool verifyChoice() {
    string response = "y";
    bool isValid = false;
    
    do {
        cout << "Would you like to input new grades? (y/n): ";
        getline(cin, response);
        
        if (response.size() > 1) { // response is greater than one char, therefore it is invalid
            isValid = false;
        } else { // response is one char, may be valid
            if (tolower(response[0]) == 'y' || tolower(response[0]) == 'n') { // input is y or n, therefore it is valid
                isValid = true;
            } else {
                isValid = false;
            }
        }
    } while (!isValid);
    
    if (tolower(response[0]) == 'y') {
        return true;
    }
    return false;

}

void myHeader(string name, int lab, string date, int question) {
    cout << "**************************************************" << endl;
    cout << "Name: " << name << endl;
    cout << "Lab #00" << lab << endl;
    cout << "Date: " << date << endl;
    cout << "Question #" << question << endl;
}

void myFooter() {
    cout << "Thank you for using the grade calculator!" << endl;
}
