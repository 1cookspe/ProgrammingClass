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
double validate(double n);
double validate(double start, double end, double n);
void myFooter();
void myHeader(string name, int labNumber, string date, int question);
int myChoiceFunction(void);
double logarithm(double x);
const double PI = 3.14159265359;


int main()
{
    // Output intro
    myHeader("Spencer Gable-Cook", 005, "November 8, 2016", 01);
    
    
    // Create and initialize variables
    int choice = 0;
    double x = 0;
    double y = 0;
    int powerTimes = 0;
    int factorialTimes = 0;
    int sineTimes = 0;
    int cosineTimes = 0;
    int exponentialTimes = 0;
    int logTimes = 0;
    
    
    // Create true loop that will end once the user enters 6 (exit)
    do {
        
        choice = myChoiceFunction();
        
        
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
                x = validate(-PI, PI, x);
                cout << "Enter N: ";
                cin >> y;
                y = validate(y);
                cout << "sin(" << x << ") = " << sine(x, y) << endl;
                sineTimes++;
                break;
            }
            case 4: { // Cosine
                cout << "Enter x: ";
                cin >> x;
                x = validate(-PI, PI, x);
                cout << "Enter N: ";
                cin >> y;
                y = validate(y);
                cout << "cos(" << x << ") = " << cosine(x, y) << endl;
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
            case 6: { // Logarithm

                // Increment number of logs used
                logTimes++;
                
                // Get value
                cout << "Enter x (0-2): ";
                cin >> x;
                
                // Verify value is between 0 and 2
                x = validate(0, 2, x);
                
                // Output to user using logarithm method
                cout << "log(" << x << ") = " << logarithm(x) << endl;
                
                break;
            }
            case 7: // Exit
                
                // Print out how many times each function was used
                cout << "The number of times each function has been used is... " << endl;
                cout << "Power: " << powerTimes << endl;
                cout << "Factorial: " << factorialTimes << endl;
                cout << "Sine: " << sineTimes << endl;
                cout << "Cosine: " << cosineTimes << endl;
                cout << "Exponential: " << exponentialTimes << endl;
                cout << "Logarithm: " << logTimes << endl;
                
                myFooter();
                
                
                break;
                
            default: { // Number entered outside of the 1 to 7 range
                break;
            }
        }
    } while (choice != 7);
}


void myHeader(string name, int labNumber, string date, int question) {
    cout << "*****************************************************" << endl;
    cout << "Name: " << name << endl;
    cout << "Lab Number: " << labNumber << endl;
    cout << "Date: " << date << endl;
    cout << "Question: " << question << endl;
}


int myChoiceFunction(void) {
    int choice = 0;
    
    
    // Ask user for calculation
    cout << "1 - Power" << endl;
    cout << "2 - Factorial" << endl;
    cout << "3 - Sine" << endl;
    cout << "4 - Cosine" << endl;
    cout << "5 - Exponential" << endl;
    cout << "6 - Natural Logarithm" << endl;
    cout << "7 - Exit" << endl;
    cout << "Please choose option: ";
    
    
    cin >> choice;
    
    while (choice < 1 || choice > 7) {
        cout << "Invalid! Please enter a number between 1 and 7: ";
        cin >> choice;
    }
    
    
    return choice;
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
    }
    else if (y < 0) { // negative exponent
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


double validate(double n) {
    // Check that value is a positive number, loop until user enters positive value
    while (n < 0) {
        cout << "Invalid! Please input a positive number! ";
        cin >> n;
    }
    return n;
}


void myFooter(void) {
    cout << "Thank you for using my calculator!" << endl;
    cout << "********************************************************************" << endl;
}

double logarithm(double x) { // Calculates natural log
    double result = 0;
    
    // Loop 20 times and add formula to total value
    for (int n = 1; n <= 20; n++) {
        result += power(-1, n + 1) * double (power(x - 1, n)) / n;
    }
    
    return result;
}

double validate(double start, double end, double n) {
    while (n < start || n > end) {
        cout << "Invalid! Please input a value greater than or equal to " << start << " and less than " << end << ": ";
        cin >> n;
    }
    return n;
}




