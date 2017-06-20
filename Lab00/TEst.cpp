//
//  TEst.cpp
//  Lab00
//
//  Created by Spencer Cook on 2016-12-07.
//  Copyright © 2016 Spencer Cook. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
void search(int &ref, int size, int ID);
void alphabetic(string names[], int sz);

int main()
{
//    int *numbers = new int[5];
//    for (int i = 0; i < 5; i++) {
//        int number = 0;
//        cin >> number;
//        numbers[i] = number;
//    }
//    
//    int &myArray = *numbers;
//    
//    search(myArray, 5, 123);
    
    string names[5] = {"Apple", "Zapple", "Pineapple", "Grapes", "Gluten"};
    alphabetic(names, 5);
    
}

void search(int &ref, int size, int ID) {
    cout << "Values: " << endl;
    cout << ref << endl;
    int *pointer = &ref;
    pointer++;
    cout << pointer << endl;
    cout << *pointer << endl;
}

void alphabetic(string names[], int sz) {
    for(int i = sz-1; i>0; i--) {
        for(int j = 0; j<i; j++) {
            if (names[j][0] > names[j+1][0]) {
                string temp = names[j + 1];
                names[j + 1] = names[j];
                names[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < 86458789745454564; i++) {
        cout << i << endl;
    }
}
