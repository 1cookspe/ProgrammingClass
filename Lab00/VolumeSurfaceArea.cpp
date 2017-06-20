//
//  VolumeSurfaceArea.cpp
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
    // Declare and set the default value to 0
    double radius = 0, height = 0, area = 0, volume = 0;
    // Create constant value of PI
    const double PI = 3.1459;
    
    // Ask user for the radius
    cout << "Enter the radius: ";
    // Get radius
    cin >> radius;
    // Ask user for height
    cout << "Enter the height: ";
    // Get height
    cin >> height;
    
    // Calculate area
    area = PI * pow(radius, 2) + PI * radius * sqrt(pow(radius, 2) + pow(height, 2));
    //Output area
    cout << "The area of the cone is " << area << endl;
    // Calculate volume
    volume = PI * pow(radius, 2) * height / 3;
    // Output volume
    cout << "The volume of the cone is " << volume << endl;
}