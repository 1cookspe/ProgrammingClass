//
//  SumDigits.cpp
//  Lab00
//
//  Created by Spencer Cook on 2016-10-03.
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Declare and set the default values to 0
    int number(0), digit1(0), digit2(0), digit3 = 0, sum = 0;
    
    // Ask user for number
    cout << "Enter the three digit number: ";
    cin >> number;
    
    // Get digit1 by dividing the overall number by 100
    digit1 = number / 100;
    
    // Get digit2 by dividing by 10 then getting the modulus of 10
    digit2 = number / 10 % 10;
    
    // Get digit3 through modulus of 10 (remainder)
    digit3 = number % 10;
    
    // Calculate overall sum
    sum = digit1 + digit2 + digit3;
    cout << "The sum of the three digits is: " << sum << endl;
}