//
//  main.cpp
//  CS172 Exam 2
//
//  Created by katie joy shaw on 6/17/14.
//  Copyright (c) 2014 Katie Shaw. All rights reserved.
//

//I affirm that all code given below was written solely by me, <give your name>, and that any help I received adhered to the rules stated for this exam.

#include <iostream>
#include "Runner.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define RUNNERFILEPATH "/Users/katidid/Documents/COMP SCI 172/Exam 2/CS172 Exam 2/CS172 Exam 2/Runners.txt"
#define WHITERUNNERS "/Users/katidid/Documents/COMP SCI 172/Exam 2/CS172 Exam 2/CS172 Exam 2/WhiteRunners.txt"
#define YELLOWRUNNERS "/Users/katidid/Documents/COMP SCI 172/Exam 2/CS172 Exam 2/CS172 Exam 2/YellowRunners.txt"
#define GREENRUNNERS "/Users/katidid/Documents/COMP SCI 172/Exam 2/CS172 Exam 2/CS172 Exam 2/GreenRunners.txt"
#define ORANGERUNNERS "/Users/katidid/Documents/COMP SCI 172/Exam 2/CS172 Exam 2/CS172 Exam 2/OrangeRunners.txt"
#define BLUERUNNERS "/Users/katidid/Documents/COMP SCI 172/Exam 2/CS172 Exam 2/CS172 Exam 2/BlueRunners.txt"
#define LILACRUNNERS "/Users/katidid/Documents/COMP SCI 172/Exam 2/CS172 Exam 2/CS172 Exam 2/LilacRunners.txt"
#define REDRUNNERS "/Users/katidid/Documents/COMP SCI 172/Exam 2/CS172 Exam 2/CS172 Exam 2/RedRunners.txt"

void outputToColorFile(vector<Runner> AllRunners, ofstream &FileName, int MinPace, int MaxPace, string Filenameforprinting);


int main()
{
    
    vector<Runner> allRunners;
    
    string currentFirstName;
    string currentLastName;
    int currentPace;
    
    // Retrieving runners' information from file
    
    ifstream runnerFile;
    runnerFile.open (RUNNERFILEPATH, fstream::in);
    
    while(!runnerFile.eof())
    {
        runnerFile >> currentFirstName >> currentLastName >> currentPace;
        allRunners.push_back(Runner(currentFirstName, currentLastName, currentPace));
        //cout << currentFirstName;

    }
    
    runnerFile.close();

    // Print original vector (for testing purposes)
    
    for(int i = 0; i < allRunners.size(); i++)
    {
        cout << allRunners[i].get_firstname() << " " << allRunners[i].get_lastname() << " " << allRunners[i].get_pace() << endl;
    }
    
    
    // Arrange vector by paces
    
    Runner temp;
    for (int i = 0; i < allRunners.size()-1; i++)
    {
        for (int j = allRunners.size()-1; j > 0; j--)
        {
            if (allRunners[j].get_pace() < allRunners[j-1].get_pace())
            {
                temp = allRunners[j];
                allRunners[j] = allRunners[j-1];
                allRunners[j-1] = temp;
            }
        }
    }
    
    // Print sorted vector (for testing purposes)

    cout << endl << endl << endl << "SORTED VETOR:" << endl;
    for(int i = 0; i < allRunners.size(); i++)
    {
        cout << allRunners[i].get_firstname() << " " << allRunners[i].get_lastname() << " " << allRunners[i].get_pace() << endl;
    }
    
    // Sort into sections by color and output to files
    
    string _fileNameForPrinting = "white";
    
        //white
    ofstream runnerFileWhite;

    runnerFileWhite.open (WHITERUNNERS, fstream::out | fstream::app);
    outputToColorFile(allRunners, runnerFileWhite, 0, 360, _fileNameForPrinting);
    
    runnerFileWhite.close();
    
    
        //yellow
    ofstream runnerFileYellow;
    
    _fileNameForPrinting = "yellow";
    
    runnerFileYellow.open (YELLOWRUNNERS, fstream::out | fstream::app);
    outputToColorFile(allRunners, runnerFileYellow, 361, 420, _fileNameForPrinting);
    
    runnerFileYellow.close();
    
    
        //green
    ofstream runnerFileGreen;
    
    _fileNameForPrinting = "green";
    
    runnerFileGreen.open (GREENRUNNERS, fstream::out | fstream::app);
    outputToColorFile(allRunners, runnerFileGreen, 421, 480, _fileNameForPrinting);
    
    runnerFileGreen.close();
    
    
        //orange
    ofstream runnerFileOrange;
    
    _fileNameForPrinting = "orange";
    
    runnerFileOrange.open (ORANGERUNNERS, fstream::out | fstream::app);
    outputToColorFile(allRunners, runnerFileOrange, 481, 540, _fileNameForPrinting);
    
    runnerFileOrange.close();
    
    
        //blue
    ofstream runnerFileBlue;
    
    _fileNameForPrinting = "blue";
    
    runnerFileBlue.open (BLUERUNNERS, fstream::out | fstream::app);
    outputToColorFile(allRunners, runnerFileBlue, 541, 600, _fileNameForPrinting);
    
    runnerFileBlue.close();
    
    
        //lilac
    ofstream runnerFileLilac;
    
    _fileNameForPrinting = "lilac";
    
    runnerFileLilac.open (LILACRUNNERS, fstream::out | fstream::app);
    outputToColorFile(allRunners, runnerFileLilac, 601, 720, _fileNameForPrinting);
    
    runnerFileLilac.close();
    
    
        //red
    ofstream runnerFileRed;
    
    _fileNameForPrinting = "red";
    
    runnerFileRed.open (REDRUNNERS, fstream::out | fstream::app);
    outputToColorFile(allRunners, runnerFileRed, 721, 1200, _fileNameForPrinting);
    
    runnerFileRed.close();
    
    
}


void outputToColorFile(vector<Runner> AllRunners, ofstream &FileName, int MinPace, int MaxPace, string Filenameforprinting)
{
    
    cout << endl << endl << "OUTPUTTING TO " << Filenameforprinting << "FILE:" << endl << endl;
    for (int i = 0; i < AllRunners.size(); i++)
    {
        if(AllRunners[i].get_pace() >= MinPace && AllRunners[i].get_pace() <= MaxPace)
        {
            FileName << AllRunners[i].get_firstname() << " " << AllRunners[i].get_lastname() << " " << AllRunners[i].get_pace() << endl;
            cout << AllRunners[i].get_firstname() << " " << AllRunners[i].get_lastname() << " " << AllRunners[i].get_pace() << endl;
            
            // Printed for testing purposes
        }
    }
}




