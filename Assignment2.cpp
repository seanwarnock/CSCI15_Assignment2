  /*
Sean Warnock
CSCI 15 Fall 2018

http://www.chabotcollege.edu/faculty/kmehl/csci15/WordCount2.pdf
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#ifdef _WIN32
  #include <windows.h>
#endif
#ifdef __linux__
//One of these days I'll use this.
#endif

#define ASSIGNMENT "CSCI 15 Assignment 2"

using namespace std;

const char STRINGTOKENS[] = " .";
const int MAXWORDS = 100;
const int MAXWORDLENGHT = 16;

void LineParser(char LineToParse[], char arraytohold[MAXWORDS][MAXWORDLENGHT], int arraywordcount[MAXWORDS])
{
    char *wordholder;
    int counter;
    bool FountIt;

    wordholder = strtok(LineToParse, STRINGTOKENS);

    while (wordholder != NULL)
    {
        //cout << endl << "chk:" << wordholder;
        counter = 0;
        FountIt = false;

        while ((counter < MAXWORDS) && (FountIt == false))
        {
            //cout << "Check " << counter << endl;
            if (strcmp (arraytohold[counter], "") == 0)
            {
                strcpy(arraytohold[counter], wordholder);
                arraywordcount[counter]++;
                FountIt = true;
            //      cout <<  "Array:" << ArrayToHold[counter].FoundWord;
            //    cout << "Adding:" << wordholder << endl;
            }
            else if (strcmp (arraytohold[counter], wordholder) == 0)
            {
                arraywordcount[counter]++;
                FountIt = true;
              //  cout << "Updating:" << wordholder << endl;
            }
            else
            {
                counter++;
                //cout << "inc:" << counter;
            }
        }
        wordholder = strtok(NULL, STRINGTOKENS);
    }
}

int main(int argc, char* argv[])
{
    ifstream inFile;
    ofstream outFile;
    char linestring[MAXWORDS];
    //WordItem ArrayHold [MAXWORDS];
    char arrayofwords [MAXWORDS][MAXWORDLENGHT] = {""};
    int arrayofwordcounts [MAXWORDS] = {0};
    char bigstring[16] = "";
    char smallstring[16] = "";
    int totalwords = 0;
    //uniquewords = This will be count the elements in arrayhold after program run.
    int linenumber = 0;
    int i;

//Setup the console.
    SetConsoleTitle(ASSIGNMENT);
    system("cls");

//Confirm if the correct number of arguments are received.  This does not verify if the arguments are "OK".
    if (argc < 3)
    {
        cout << "Please enter the <SOURCE> file and the <DESTINATION> file.";
        exit(90);
    }

//Open each of the files
    inFile.open(argv[1]);
    outFile.open(argv[2]);

//Pull the first line of the file to read.
    inFile.getline(linestring,MAXWORDS,'\n');
    cout << linestring;
    outFile << linestring;
    linenumber++;
    LineParser(linestring, arrayofwords, arrayofwordcounts);

//Now that we have the first line start looping through the remainder of the file or stop if
//the file is empty.  This deals with the last line of the file and NOT putting
//and extra newline.
    while (!inFile.eof())
    {
        cout << endl;
        outFile << endl;
        linenumber++;

        inFile.getline(linestring,MAXWORDS,'\n');
        cout << linestring;
        outFile << linestring;
        LineParser(linestring,  arrayofwords, arrayofwordcounts);

    }

    cout << endl << "Source file: " << argv[1] << " Out file: " << argv[2] << endl;
    outFile << endl << "Source file: " << argv[1] << " Out file: " << argv[2] << endl;
    cout << endl << setw(16) << "Total lines : " << linenumber << endl;
    outFile << endl << setw(16) << "Total lines : " << linenumber << endl;
    cout << setw(16) << "Word" << setw(10) << "Times" << endl;
    outFile << setw(16) << "Word" << setw(10) << "Times" << endl;

    i = 0;
    strcpy(bigstring,arrayofwords[i]);
    strcpy(smallstring,arrayofwords[i]);

    while ((strcmp (arrayofwords[i], "") != 0) && (i < MAXWORDS))
    {
        totalwords = totalwords + arrayofwordcounts[i];
        cout << setw(16) << arrayofwords[i] << setw(10) << arrayofwordcounts[i] << endl;
        outFile << setw(16) << arrayofwords[i] << setw(10) << arrayofwordcounts[i] << endl;
        if (strlen(bigstring) < strlen(arrayofwords[i]))
            {
                strcpy(bigstring,arrayofwords[i]);
            }
        else if (strlen(smallstring) > strlen(arrayofwords[i]))
            {
                strcpy(smallstring,arrayofwords[i]);
            }
        i++;
    }

    cout << "Unique Words : " << i << endl;
    outFile << "Unique Words : " << i << endl;
    cout << "Total Words : "  << totalwords << endl;
    outFile << "Total Words : "  << totalwords << endl;
    cout << "The largest word was :" << bigstring << endl;
    outFile << "The largest word was :" << bigstring << endl;
    cout << "The smallest word was : " << smallstring << endl;
    outFile << "The smallest word was : " << smallstring << endl;
    inFile.close();
    outFile.close();
}
