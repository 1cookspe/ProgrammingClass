//
//  Login.cpp
//  Lab00
//
//  Created by Spencer Cook on 2016-10-14.
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include "Login.hpp"
#include <iostream>
using namespace std;

int main()
{
    //Create and initialize variables
    string firstName = "", lastName = "", username = "", password = "", enteredUser = "", enteredPass = "";
    int counter = 3;
    
    // Get data
    cout << "Enter your full name: ";
    cin >> firstName >> lastName;
    cin.ignore();
    cout << "Create username: ";
    getline(cin, username);
    cout << "Create password: ";
    getline(cin, password);
    
    // Ask user for login credientials
    cout << "------------------------------------------------------------" << endl;
    cout << "LOGIN SESSION" << endl;
    cout << "Username: ";
    getline(cin, enteredUser);
    cout << "Password: ";
    getline(cin, enteredPass);
    
    while (enteredUser != username || enteredPass != password) {
        cout << "Invalid credentials! Please login again!" << endl;
        cout << "You have " << counter << " logins remaining..." << endl;
        cout << "Username: ";
        getline(cin, enteredUser);
        cout << "Password: ";
        getline(cin, enteredPass);
        counter--;
        
        if (counter == 0) {
            cout << "You have tried to login too many times! Good-bye!"  << endl;
            return 0;
        }
    }
    
    cout << "Welcome " << firstName << " " << lastName << "!" << endl;
}
