// Name: Spencer Gable-Cook
// Student #: 250922065
// Date: November 1, 2016
// Program Mission: To find the max, min and average of a set of numbers, along with the even and odd values

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Declare function calculateAverage, along with its return type (double) and parameters (int sum and int n)
double calculateAverage(double sum, int n);

// Create and initialize variables, to default value of 0
int N = 0;
int n = 0;
int minimum = 0;
int maximum = 0;
int maximumEven = 0;
int minimumEven = 0;
int totalSum = 0;
int numberEvens = 0;
int evenSum = 0;
int numberOdds = 0;
int minimumOdds = 0;
int maximumOdds = 0;
int oddSum = 0;

int main()
{
    cout << "**************************" << endl;
    cout << "Name: Spencer Gable-Cook" << endl;
    cout << "Date: November 1, 2016" << endl;
    cout << "Min, Max, and Average Calculator" << endl;
    cout << "Program Mission: To find the max, min and average of a set of numbers, along with the even and odd values" << endl;
    cout << "**************************" << endl;
    
    // Get N
    cout << "Enter value for N: ";
    cin >> N;
    
    // Validate N is between 1 and 300
    while (N < 1 || N > 300) {
        cout << "Invalid! Please enter a number between 1 and 300: ";
        cin >> N;
    }
    
    // Loop N times to get N numbers
    for (int i = 1; i <= N; i++) {
        cout << "Enter integer " << i << ":";
        cin >> n;
        
        // Validate number is positive
        while (n < 0) {
            cout << "Invalid! Enter a positive integer: ";
            cin >> n;
        }
        
        // If it is the first number (first iteration in loop), the max and min and initially set to n
        if (i == 1) {
            maximum = n;
            minimum = n;
        } else if (n > maximum) { // if n is greater than max, the new max is n
            maximum = n;
        } else if (n < minimum) { // if n is less than min, the new min is n
            minimum = n;
        }
        
        // Add number to totalSum
        totalSum += n;
        
        // For odd and even numbers
        if (n % 2 == 0) { // even
            numberEvens++; // increment number of even numbers
            evenSum += n; // add number to evenSum
            if (numberEvens == 1) { // if it is the first even number, max and min are intially set to n
                maximumEven = n;
                minimumEven = n;
            } else if (n > maximumEven) { // if n is greater than the max even, max even is now n
                maximumEven = n;
            } else if (n < minimumEven) { // if n is less than min even, min even is now n
                minimumEven = n;
            }
        } else { // number is odd
            numberOdds++; // increase number of odd numbers
            oddSum += n; // add number to odd total
            if (numberOdds == 1) { // if it is the first odd number, min odd and max odd are initially set to n
                maximumOdds = n;
                minimumOdds = n;
            } else if (n > maximumOdds) { // if n is greater than the max odd, then max odd is now n
                maximumOdds = n;
            } else if (n < minimumOdds) { // if n is less than the min odd, then min odd is now n
                minimumOdds = n;
            }
        }
    }
    
    
    // Output results
    cout << "Maximum entered number: " << maximum << endl;
    cout << "Minimum entered number: " << minimum << endl;
    cout << "Average: " << calculateAverage(totalSum, N) << endl; // calculate average using method
    
    if (numberEvens != 0) { // checks that there is at least 1 even number, to avoid an undefined average (divide by 0)
        cout << "Maximum Even number: " << maximumEven << endl;
        cout << "Minimum Even number: " << minimumEven << endl;
        cout << "Average even numbers: " << calculateAverage(evenSum, numberEvens) << endl;
    } else {
        cout << "No even numbers entered!" << endl;
    }
    
    if (numberOdds != 0) { // checks that there is at least 1 odd number, to avoid an undefined average (divide by 0)
        cout << "Maximum Odd number: " << maximumOdds << endl;
        cout << "Minimum Odd number: " << minimumOdds << endl;
        cout << "Average odd numbers: " << calculateAverage(oddSum, numberOdds) << endl;
    } else {
        cout << "No odd numbers entered!" << endl;
    }
    
}


double calculateAverage(double sum, int n) {
    // calculates average by dividing sum by the number of numbers
    return sum / n;
}



