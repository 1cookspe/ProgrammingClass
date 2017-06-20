//
//  Arithmetic.cpp
//  Lab00
//
//  Created by Spencer Cook on 2016-10-03.
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    // Declare and initialize variables to 0
    double y1(0), y2(0), x1 = 0, x2 = 0, x3 = 0;
    
    // Get x values
    cout << "Enter the x values (x1, x2, and x3): ";
    cin >> x1 >> x2 >> x3;
    
    // Calculate y1 and y2
    y1 = pow((exp(x2) + x1 * sin(x3)), 3) + abs(sin(x3) / x1);
    y2 = exp(tan(x2)) + log(exp(x3));
    
    // Output y1 and y2
    cout << "The calculated value of y1 is: " << y1 << endl;
    cout << "The calculated value of y2 is : " << y2 << endl;
}