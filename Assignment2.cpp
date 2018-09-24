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

const char StringTokens[] = " ,.";
const int MaxWords = 100;

struct WordItem
   {
    char FoundWord[16] = "";
    int TimesUsed = 0;
  };

void LineParser(char LineToParse[], WordItem ArrayToHold[])
{
    char *WordHolder;
    int counter;
    bool FountIt;

    WordHolder = strtok(LineToParse, StringTokens);

    while (WordHolder != NULL)
    {
        //cout << endl << "chk:" << WordHolder;
        counter = 0;
        FountIt = false;

        while ((counter < MaxWords) && (FountIt == false))
        {
            //cout << "Check " << counter << endl;
            if (strcmp (ArrayToHold[counter].FoundWord, "") == 0)
            {
                strcpy(ArrayToHold[counter].FoundWord, WordHolder);
                ArrayToHold[counter].TimesUsed++;
                FountIt = true;
          //      cout <<  "Array:" << ArrayToHold[counter].FoundWord;
            //    cout << "Adding:" << WordHolder << endl;
            }
            else if (strcmp (ArrayToHold[counter].FoundWord, WordHolder) == 0)
            {
                ArrayToHold[counter].TimesUsed++;
                FountIt = true;
              //  cout << "Updating:" << WordHolder << endl;
            }
            else
            {
                counter++;
                //cout << "inc:" << counter;
            }
        }

        WordHolder = strtok(NULL, StringTokens);
    }
}

int main(int argc, char* argv[])
{
    ifstream inFile;
    ofstream outFile;
    char LineString[MaxWords];
    WordItem ArrayHold [MaxWords];
    int bigstring = 0;
    int smallstring = 0;
    int totalwords = 0;
    //uniquewords = This will be count the elements in arrayhold after program run.
    int LineNumber = 0;

//Setup the console.
    SetConsoleTitle(ASSIGNMENT);
    system("cls");

//Confirm if the correct number of arguments are received.  This does not verify if the arguments are "OK".
    if (argc < 3)
    {
        cout << "Please enter the <SOURCE> file and the <DESTINATION> file.";
        exit(90);
    }

    cout << "you entered " << argc << " arguments " << argv[1] << " " << argv[2] << endl;

//Open each of the files
    inFile.open(argv[1]);
    outFile.open(argv[2]);

//Pull the first line of the file to read.
    inFile.getline(LineString,MaxWords,'\n');
    cout << LineString;
    outFile << LineString;
    LineNumber++;
    LineParser(LineString, ArrayHold);

//Now that we have the first line start looping through the remainder of the file or stop if
//the file is empty.  This deals with the last line of the file and NOT putting
//and extra newline.
    while (!inFile.eof())
    {
        cout << endl;
        outFile << endl;
        LineNumber++;

        inFile.getline(LineString,MaxWords,'\n');
        cout << LineString;
        outFile << LineString;
        LineParser(LineString, ArrayHold);

    }

    cout << endl << "Total lines : " << LineNumber << endl;

    cout << "Word" << "Times" << endl;
    for (int i=0;i<100;i++)
    {
        cout << ArrayHold[i].FoundWord << ArrayHold[i].TimesUsed << endl;
    }

    inFile.close();
    outFile.close();

}
