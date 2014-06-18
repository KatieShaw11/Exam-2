//
//  Runner.h
//  CS172 Exam 2
//
//  Created by katie joy shaw on 6/17/14.
//  Copyright (c) 2014 Katie Shaw. All rights reserved.
//


//I affirm that all code given below was written solely by me, <give your name>, and that any help I received adhered to the rules stated for this exam.

#ifndef __CS172_Exam_2__Runner__
#define __CS172_Exam_2__Runner__

#include <iostream>
using namespace std;

class Runner
{
public:
    Runner();
    Runner(string First, string Last, int Pace);
    string get_firstname();
    string get_lastname();
    int get_pace();
    void set_firstname(string);
    void set_lastname(string);
    void set_pace(int);
private:
    string firstname;
    string lastname;
    int pace;
};

#endif /* defined(__CS172_Exam_2__Runner__) */
