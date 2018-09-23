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

int main(int argc, char* argv[])
{
    const char StringTokens[] = " ,.";
    const int MaxWords = 100;

    ifstream inFile;
    ofstream outFile;
    char LineString[MaxWords];
    char ArrayHold [MaxWords][16];
    int ArrayCount [MaxWords];
    int bigstring = 0;
    int smallstring = 0;
    int totalwords = 0;
    //uniquewords = This will be count the elements in arrayhold after program run.
    int LineNumber = 0;

    char *WordHolder;


//Setup the console.
    SetConsoleTitle(ASSIGNMENT);
    system("cls");

//Confirm if the correct number of arguments are received.  This does not verify if the arguments are "OK".
    if (argc < 3)
    {
        cout << "Please enter the <SOURCE> file and the <DESTINATION> file.";
        exit(90);
    }

    cout << "you entered " << argc << " arguments " << argv[1] << " " << argv[2];

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    inFile.getline(LineString,MaxWords,'\n');

    cout << LineString;
    outFile << LineString;
    //need to parse this first string here
//        strtok(LineString, ' ');
    while (!inFile.eof())
    {
        cout << endl;
        outFile << endl;
        LineNumber++;

        inFile.getline(LineString,MaxWords,'\n');
        cout << LineString;
        outFile << LineString;

/*
        WordHolder = strtok(LineString, StringTokens);
        while (LineString != NULL)
        {
            WordHolder = strtok(NULL, StringTokens);
        }
        //need to part this first string here
        //        strtok(LineString, ' ');
        //Big and small is compated to the biggest item in the array and smallest item of the array.  Only update this value if it is bigger or smaller.
*/
    }

    cout << endl << "Total lines : " << LineNumber << endl;
    inFile.close();
    outFile.close();

}
