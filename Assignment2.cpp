/*
Sean Warnock
CSCI 15 Fall 2018

http://www.chabotcollege.edu/faculty/kmehl/csci15/WordCount2.pdf

Write a C++ program that reads lines of text from a file using the ifstream getline()method, tokenizes the lines into words ("tokens")using strtok(), and keeps statistics on the data in the file.  Your input and output file names will be supplied to your program on the command line, which you will access using argc and argv[].
You need to count the total number of words seen, the number of unique words, the count of each individual word, and the number of lines.
By "unique words",I just mean words that have not been seen yetin the program.  Once a word has been seen, it is no longer unique if or when you see it again.
Also, remember and print the longest and shortest words in the file.  If there is a tie for longest or shortest word, you may resolve the tie in any consistent manner (e.g., use either the first one or the last one found, but use the same method for both longest and shortest).
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

#define ASSIGNMENT "CSCI 15 Assignment 2"

using namespace std;

int main()
{
    string stringInFileName = "test.txt";
    ifstream inFile;
    string stringOutFileName = "testout.txt";
    ofstream outFile;
    char LineString[100];


    SetConsoleTitle(ASSIGNMENT);
    system("cls");

     cout << "Please enter a file name in the local path to open. : ";
    //cin >> stringInFileName;
    cout << endl;
    cout << "Please enter a file name in the local path to write. : ";
    //cin >> stringOutFileName;
    cout << endl;

    inFile.open(stringInFileName);
    outFile.open(stringOutFileName);

    while (!inFile.eof())
    {
        inFile.getline(LineString,100,'\n');
        strtok(LineString, ' ');
//need to test for "last line"
        cout << LineString << endl;
        outFile << LineString << endl;
    }

    inFile.close();
    outFile.close();
}
