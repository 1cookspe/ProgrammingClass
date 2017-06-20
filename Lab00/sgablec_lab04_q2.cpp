// Name: Spencer Gable-Cook
// Student #: 250922065
// Date: November 1, 2016
// Program Mission: To provide the user with a scientific calculator
#include <iostream>
#include <string>
using namespace std;
#include <cmath>


// Declare methods
double power(double x, int y);
double factorial(int n);
double sine(double x, int N);
double cosine(double x, int N);
double exponential(double x, int N);
int validate(int n);

int main()
{
    // Welcome screen
    cout << "**************************" << endl;
    cout << "Name: Spencer Gable-Cook" << endl;
    cout << "Date: November 1, 2016" << endl;
    cout << "My Calculator!" << endl;
    cout << "Program Mission: To provide the user with a scientific calculator" << endl;
    cout << "**************************" << endl;
    
    // Create and initialize variables
    int choice = 0;
    double x = 0;
    double y = 0;
    int powerTimes = 0;
    int factorialTimes = 0;
    int sineTimes = 0;
    int cosineTimes = 0;
    int exponentialTimes = 0;
    
    
    // Create true loop that will end once the user enters 6 (exit)
    while (true) {
        // Ask user for calculation
        cout << "1 - Power" << endl;
        cout << "2 - Factorial" << endl;
        cout << "3 - Sine" << endl;
        cout << "4 - Cosine" << endl;
        cout << "5 - Exponential" << endl;
        cout << "6 - Exit" << endl;
        cout << "Please choose option: ";
        
        cin >> choice;
        
        
        // Use switch statement to determine user's choice
        switch (choice) {
            case 1: { // Power function
                // Get parameters from user
                cout << "Enter base: ";
                cin >> x;
                cout << "Enter exponent: ";
                cin >> y;
                // Call method and output result
                cout << x << "^" << y << " = " << power(x, y) << endl;
                // Increment number of times this function has been used
                powerTimes++;
                break;
            }
            case 2: { // Factorial
                cout << "Enter number: ";
                cin >> x;
                x = validate(x);
                cout << x << "! = " << factorial(x) << endl;
                factorialTimes++;
                break;
            }
            case 3: { // Sine
                cout << "Enter x: ";
                cin >> x;
                cout << "Enter N: ";
                cin >> y;
                y = validate(y);
                cout << "sin(" <<  x << ") = " << sine(x, y) << endl;
                sineTimes++;
                break;
            }
            case 4: { // Cosine
                cout << "Enter x: ";
                cin >> x;
                cout << "Enter N: ";
                cin >> y;
                y = validate(y);
                cout << "cos(" <<  x << ") = " << cosine(x, y) << endl;
                cosineTimes++;
                break;
            }
            case 5: { // Exponential
                cout << "Enter x: ";
                cin >> x;
                cout << "Enter N: ";
                cin >> y;
                y = validate(y);
                cout << "exp(" << x << ") = " << exponential(x, y) << endl;
                exponentialTimes++;
                break;
            }
            case 6: { // Exit
                // Print out how many times each function was used
                cout << "Thank you for using the calculator!" << endl;
                cout << "The number of times each function has been used is... " << endl;
                cout << "Power: " << powerTimes << endl;
                cout << "Factorial: " << factorialTimes << endl;
                cout << "Sine: " << sineTimes << endl;
                cout << "Cosine: " << cosineTimes << endl;
                cout << "Exponential: " << exponentialTimes << endl;
                // Return 0 to stop the loop and program
                return 0;
                break;
            }
            
            default: { // Number entered outside of the 1 to 6 range
                cout << "Invalid! Enter a number from 1 to 6! Please try again! " << endl;
                // Call continue to loop to new iteration of the loop to get a valid input from the user
                continue;
                break;
            }
        }
    }
}


double power(double x, int y) {
    double answer = 1;
    // Positive exponent
    if (y > 0) {
        // Loop as many times as the exponent value
        for (int n = 1; n <= y; n++) {
            // Multiply by the base exponent times
            answer *= x;
        }
    } else if (y < 0) { // negative exponent
        // Loop as many times as the exponent value, start at -1 due to the negative y value
        for (int n = -1; n >= y; n--) {
            // Multiply by 1 / x due to the negative exponent
            answer *= 1.0 / x;
        }
    }
    return answer;
}


double factorial(int n) {
    double factorial = 1;
    // Loop until n to be multiplied is 1
    for (; n > 0; n--) {
        // Multiply factorial by the number below it
        factorial = factorial * n;
    }
    
    return factorial;
}


double sine(double x, int N) {
    double answer = 0;
    // Loop N times
    for (int n = 0; n <= N; n++) {
        // Add to answer using formula
        answer += (power(-1, n) / factorial(2 * n + 1)) * power(x, 2 * n + 1);
    }
    return answer;
}


double cosine(double x, int N) {
    double answer = 0;
    // Loop N times
    for (int n = 0; n <= N; n++) {
        // Add to answer using formula
        answer += (power(-1, n) / factorial(2 * n)) * power(x, 2 * n);
    }
    return answer;
}


double exponential(double x, int N) {
    double answer = 0;
    // Loop N times
    for (int n = 0; n <= N; n++) {
        // Add to answer using formula
        answer += (power(x, n) / factorial(n));
    }
    return answer;
}

int validate(int n) {
    // Check that value is a positive number, loop until user enters positive value
    while (n < 0) {
        cout << "Invalid! Please input a positive number! ";
        cin >> n;
    }
    return n;
}





