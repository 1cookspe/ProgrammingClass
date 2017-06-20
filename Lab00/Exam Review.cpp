#include <iostream>
using namespace std;
#include <string>
int main () {
    string k = "hello world!";
    int i = 0;
    /* stringName.length() gives the length of
     the string called stringName */
    while (i<k.length())
    {
        k[i] = toupper(k[i]);
        i++;
    }
    cout<<k<<endl;
}



