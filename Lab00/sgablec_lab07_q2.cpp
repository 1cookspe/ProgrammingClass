//
//  sgablec_lab07_q2.cpp
//  Lab00
//
//  Created by Spencer Cook on 2016-11-20.
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include <iostream>
using namespace std;

// Methods
int getValidValue(int lowerLimit, int upperLimit);
void calculateAverage(double *average, int N);
bool validYesOrNo();
void myHeader(string name, int lab, string date, int question);
void myFooter();

int main()
{
    myHeader("Spencer Gable-Cook", 7, "Tuesday November 22, 2016", 2);
    
    int N = 0;
    // Create double a, initialize to 0, to serve as the pointed variable of the average pointer
    double a = 0;
    // Initialize value of pointer average by pointing to the value of double a
    double *average = &a;
    
    do {
    
        // Get user's input of # of numbers to be averaged
        N = getValidValue(1, 20);

        calculateAverage(average, N);
    
        cout << "The average of these numbers is " << *average << endl;
        
    } while (validYesOrNo()); // loop again if user decides to play again
    
    myFooter();
    
}

int getValidValue(int lowerLimit, int upperLimit) {
    string number = "";
    int value = 0;
    cout << "Enter a value between " << lowerLimit << " and " << upperLimit << ": ";
    getline(cin, number);
    
    // check an integer value is input
    for (unsigned int i = 0; i < (int)number.size(); i++) {
        if (i == 0) {
            if (!((number[0]=='-') || number[0] >= '0' && number[0] <= '9')) {
                cout << "Invalid! Enter an integer: ";
                getline(cin, number);
                i = -1;
            }
        } else if (!(number[i] >= '0' && number[i] <= '9')) {
            cout << "Invalid! Enter an integer: ";
            getline(cin, number);
            i = -1;
        }
    }
    
    value = atoi(number.c_str());
    
    while (value < lowerLimit || value > upperLimit) {
        cout << "Invalid! ";
        value = getValidValue(lowerLimit, upperLimit);
    }
    
    return value;
}

void calculateAverage(double *average, int N) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += getValidValue(-50, 600);
    }
    
    *average = (double)total / N;
    
}

bool validYesOrNo() {
    string response = "y";
    bool isValid = false;
    
    do {
        cout << "Would you like to play again? (y/n): ";
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
    cout << "**************************************************" << endl;
}

void myFooter() {
    cout << "Thank you for using the average calculator!" << endl;
}
