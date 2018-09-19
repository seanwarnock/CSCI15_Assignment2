/*
Sean Warnock
CSCI 15 Fall 2018

Write a C++ program that reads lines of text from a file using the ifstream getline()method, tokenizes the lines into words ("tokens")using strtok(), and keeps statistics on the data in the file.  Your input and output file names will be supplied to your program on the command line, which you will access using argc and argv[].
You need to count the total number of words seen, the number of unique words, the count of each individual word, and the number of lines.
By "unique words",I just mean words that have not been seen yetin the program.  Once a word has been seen, it is no longer unique if or when you see it again.
Also, remember and print the longest and shortest words in the file.  If there is a tie for longest or shortest word, you may resolve the tie in any consistent manner (e.g., use either the first one or the last one found, but use the same method for both longest and shortest).
*/
#include <iostream>
#include <string>
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

int ReadFile()
{
    string stringInFileName = "test.txt";
    ifstream inFile;
    char LineString[100];

    //cout << "Please enter a file name in the local path to open. : ";
    //cin >> stringInFileName;
    inFile.open(stringInFileName);

    cout << 'Got readfile' << endl;
    while (!inFile.eof())
    {
        inFile.getline(LineString,100,'\n');
        //intfigetline(inFile, LineString);
        cout << LineString;
    }

    return 0;
}

int OutFile()
{
    string stringOutFileName;
    ofstream outFile;

    cout << "Please enter a file name in the local path to write. : ";
    cin >> stringOutFileName;
    //ofsteam
}

int main()
{
    SetConsoleTitle(ASSIGNMENT);
    system("cls");

    ReadFile();
}
