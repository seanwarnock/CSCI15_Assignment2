/*
Sean Warnock
CSCI 15 Fall 2018

*/
#include <iostream>
#include <cstring>
//#include <iomanip>
#include <fstream>
//#include <math.h>
#ifdef _WIN32
  #include <windows.h>
#endif
#ifdef __linux__

#endif

#define ASSIGNMENT "CSCI 15 Lab 2"

using namespace std;

int main()
{
    char str[100] = "This is a simple C-string";
    char *pstr =  "This is a declaration of a pointer to a C-string";
    char *qstr = pstr;
    char *rstr = str;

    cout << str << endl;
    cout << *pstr << endl;
    cout << *qstr << endl;
    cout << *rstr << endl;

    str[10] = '@';
    cout << str << endl;
    cout << *pstr << endl;
    cout << *qstr << endl;
    cout << *rstr << endl;

/*
Run time crash crash on next line.
    pstr[10] = '$';
    cout << str << endl;
    cout << *pstr << endl;
    cout << *qstr << endl;
    cout << *rstr << endl;
*/

    pstr = "Hello World";
    cout << str << endl;
    cout << *pstr << endl;
    cout << *qstr << endl;
    cout << *rstr << endl;

    strcpy(str,"Goodbye") ;
    cout << str << endl;
    cout << *pstr << endl;
    cout << *qstr << endl;
    cout << *rstr << endl;
}
