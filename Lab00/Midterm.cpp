//
//  Midterm.cpp
//  Lab00
//
//  Created by Spencer Cook on 2016-10-20.
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include "Midterm.hpp"
#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    int N = 20, x = 0, n = 0;
    double answer = 0;
    
    cout << "Enter x: ";
    cin >> x;
    
    while (n <= N) {
        double factorial = 1;
        int counter = n;
        
        while (counter > 0) {
            factorial *= counter;
            counter--;
        }
        
        answer += pow(x, n) / factorial;
        
        n++;
    }
    
    cout << answer;
    
}

void studentsMethod() {
    int numStudents(0), mark(0), highestGrade(0), lowestGrade(0), total(0);
    double numPassed = 0, averageGrade = 0;
    
    cout << "how many students: ";
    cin >> numStudents;
    
    while (numStudents <= 0) {
        cout << "try again! input a positive number: ";
        cin >> numStudents;
    }
    
    for (int i = 1; i <= numStudents; i++) {
        cout << "Enter mark: ";
        cin >> mark;
        
        if (i == 1 || mark >= highestGrade) {
            highestGrade = mark;
            lowestGrade = mark;
        } else if (mark <= lowestGrade) {
            lowestGrade = mark;
        }
        
        total += mark;
        
        if (mark > 50) {
            numPassed++;
        }
    }
    
    cout << "Lowest mark: " << lowestGrade << endl;
    cout << "Highest grade: " << highestGrade << endl;
    numPassed = numPassed / numStudents * 100;
    cout << "PErcentage passed: " << numPassed << endl;
    averageGrade = (double)total / numStudents;
    cout << "Average mark: " << averageGrade << endl;
}