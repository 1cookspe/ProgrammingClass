//
//  Cosine.cpp
//  Lab00
//
//  Final version, modified Sunday October 16, 2016
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include "Cosine.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Declare and initialize variables
    int choice, n, i;
    const double PI = 3.14159265359;
    double x, cosine;
    char y = 'Y';
    
    while (y == 'Y') {
        // initialize variables
        x = 0, cosine = 0.0;
        n = -1, i = 1, choice = 1;
        
    // Ask user for x value
    cout << "Please enter the angle: ";
    cin >> x;
    
    // Check if amount is in radians or degrees
    cout << "1 - Radians OR 2 - Degrees?: ";
    cin >> choice;
    
    // Loop until user enters valid choice
    while (choice != 1 && choice != 2) {
        cout << "Invalid! Please input 1 for radians, or 2 for degrees: ";
        cin >> choice;
    }
    
    // If degrees, convert to radians
    if (choice == 2) {
        x = x * (PI / 180.0);
    }
        cout << x << endl;
    
    // Ask user for n value
    cout << "Enter the number of summations (N): ";
    cin >> n;
    
    // Check that user enters N value over 0
    while (n <= 0) {
        cout << "Incorrect! Please input a positive N value! ";
        cin >> n;
    }
    
    // Loop through function to calculate the cosine of the angle
    while (i <= n) {
        // calculate factorial
        double factorial = 2 * i;
        int counter = factorial - 1;
        while (counter != 0) {
            factorial *= counter;
            counter--;
        }
        
        //cout << factorial << endl;
        if (i % 2 != 0) {
            cosine += (pow(x, i * 2)) / (double)factorial;
        } else {
            cosine -= (pow(x, i * 2)) / (double)factorial;
        }
        i++;
    }
        
        // Print out cosine answer
        cosine = 1 - cosine;
        cout << "cos(" << x << ") = " << cosine << endl;
        
        // Ask if user want to do another calculation
        cout << "Would you like to calculate another angle? Y for yes, N for no: ";
        cin >> y;
    }
    
    // User is done
    cout << "Thank you for using the cosine calculator!" << endl;
}