
#include <iostream>
#include <string>
using namespace std;
// Create functions
void populateArray(double *ptr, int size);
double validateGrade();
void printTable(double &array, int *size);
void courseStatistics(double array[], int size, double &highest, double &lowest, double *average);
void sortArray(double array[], int size);
void myHeader(string name, int labNumber, string date, int question);
void myFooter();
int validateInput();
char validateChar();

int main()
{
    // output header
    myHeader("Spencer Gable-Cook", 8, "Tuesday December 6", 1);
    
    // Variables
    char yes = 'y';
    string name = "";
    int choice = 0;
    double *myArray;
    
    do {
        // Get class name
        cout << "Enter class name: ";
        getline(cin, name);
        
        // Get number of grades
        int numberOfGrades = 0;
        cout << "Enter the number of grades: ";
        cin >> numberOfGrades;
        
        // Initialize array
        const int GRADES = numberOfGrades;
        myArray = new double[GRADES];
        
        // Get values for array
        populateArray(myArray, numberOfGrades);
        
        // Ask user for what they would like to perform
        do {
            choice = validateInput();
        
            // Switch on user's selection
            switch (choice) {
                case 1: // print stats
                    printTable(myArray[0], &numberOfGrades);
                    break;
                case 2: {
                    double highestGrade = 0;
                    double lowestGrade = 0;
                    double averageGrade = 0;
                
                    courseStatistics(myArray, numberOfGrades, highestGrade, lowestGrade, &averageGrade);
                    cout << "Highest grade: " << highestGrade << endl;
                    cout << "Lowest grade: " << lowestGrade << endl;
                    cout << "Average grade: " << averageGrade << endl;
                    break;
                }
                case 3:
                    sortArray(myArray, numberOfGrades);
                    printTable(myArray[0], &numberOfGrades);
                    break;
                case 4:
                    break;

            }
        } while (choice != 4);
    
        // Delete data from that class
        cout << "Closing " << name << " file..." << endl;
        delete myArray;
        myArray = NULL;
        
        // Ask user if they want to play again
        yes = validateChar();
    } while (tolower(yes) == 'y');
        
    
    // user is done, output exit footer
    myFooter();
    
}

// Set values of array
void populateArray(double *ptr, int size) {
    for (int i = 0; i < size; i++) { // Loop through each element of the pointer array
        double grade = validateGrade(); // validate grade is between 0 and 100
        ptr[i] = grade; // set index of array to the validated grade
    }

}

double validateGrade() {
    int grade = 0;
    cout << "Enter the grade: ";
    cin >> grade;
    
    while (grade < 0 || grade > 100) { // loop while number is below 0 or above 100
        cout << "Invalid entry! Enter a grade between 0 and 100: "; // ask user to enter new value
        cin >> grade;
    }
    return (double)grade; // returns grade to caller, as a double
}

void printTable(double &array, int *size) {
    double *ptr = &array; // create pointer array with the first value as the array
    for (int i = 0; i < *size; i++) {
        cout << "Grade #" << (i + 1) << ": " << ptr[i] << endl; // print out each index of array
    }
    
}

void courseStatistics(double array[], int size, double &highest, double &lowest, double *average) {
    // create variables to count number of each letter
    double total = 0;
    double aMarks = 0;
    double aPlusMarks = 0;
    double bMarks = 0;
    double bPlusMarks = 0;
    double cMarks = 0;
    double dMarks = 0;
    double fMarks = 0;
    
    // Loop through each element in array
    for (int i = 0; i < size; i++) {
        total += array[i]; // add each value to total, to be used for the average
        if (i == 0) { // on first run, set the highest and lowest values to the first value in the array, for initialization
            highest = array[i];
            lowest = array[i];
        } else {
            if (array[i] > highest) { // value is higher than the max, so the max becomes the value
                highest = array[i];
            } else if (array[i] < lowest) { // value is lower than min, so the min becomes the value
                lowest = array[i];
            }
        }
        
        // Calculate A, B, etc
        if (array[i] >= 95) { // A+
            aPlusMarks++;
        } else if (array[i] >= 90) { // A
            aMarks++;
        } else if (array[i] >= 85) { // B+
            bPlusMarks++;
        } else if (array[i] >= 80) { // B
            bMarks++;
        } else if (array[i] >= 70) { // C
            cMarks++;
        } else if (array[i] >= 60) { // D
            dMarks++;
        } else { // F
            fMarks++;
        }
    }
    
    // Print out number of marks for each
    cout << "A+: " << aPlusMarks << endl;
    cout << "A: " << aMarks << endl;
    cout << "B+: " << bPlusMarks << endl;
    cout << "B: " << bMarks << endl;
    cout << "C: " << cMarks << endl;
    cout << "D: " << dMarks << endl;
    cout << "F: " << fMarks << endl;
    
    
    // Calculate average in pointer (dereferenced)
    *average = total / size;
}

// Sorts array from highest to lowest (descending)
void sortArray(double array[], int size) {
    for(int i = size-1; i>0; i--)
        for(int j = 0; j<i; j++)
        {
            if(array[j]<array[j+1]) // value is lower than next value, so they must be swapped
            {//swapping the array elements
                int temp = array[j+1]; // Create temporary variable to hold the next value
                array[j+1] = array[j];
                array[j] = temp; // switch values around
            }
        }
}

void myHeader(string name, int labNumber, string date, int question) {
    cout << "******************************************" << endl;
    cout << "Name: " << name << endl;
    cout << "Lab #00" << labNumber << endl;
    cout << "Date: " << date << endl;
    cout << "Question #" << question << endl;
    cout << "Program Mission: To allow users to enter, store, sort, and get data about their grades!" << endl;
    cout << "******************************************" << endl;
}

void myFooter() {
    cout << "Thank you for using the Grade Saver!" << endl;
}

int validateInput() {
    int choice = 0;
    
    // Output options to user
    cout << "Menu Options:" << endl;
    cout << "1 - Print the course grades." << endl;
    cout << "2 - Obtain course statistics." << endl;
    cout << "3 - Sort the grades" << endl;
    cout << "4 - Exit" << endl;
    cout << "Your choice: ";
    cin >> choice;
    
    while (choice < 1 || choice > 5) { // loop if user has entered a value outside of 1 to 4
        cout << "Invalid! Input a number between 1 and 4: ";
        cin >> choice;
    }
    
    return choice;
}

char validateChar() {
    char y;
    
    // Ask user if they want to enter another course
    cout << "Would you like to enter a new course? (y/n): ";
    cin >> y;
    cin.ignore();
    
    // If input is not Y/y or N/n, then they must input a new value
    while (tolower(y) != 'y' && tolower(y) != 'n') {
        cout << "Invalid! Input y/Y for yes, or n/N for no: ";
    }
    
    return y;
}
