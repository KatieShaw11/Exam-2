//
//  Runner.cpp
//  CS172 Exam 2
//
//  Created by katie joy shaw on 6/17/14.
//  Copyright (c) 2014 Katie Shaw. All rights reserved.
//

//I affirm that all code given below was written solely by me, <give your name>, and that any help I received adhered to the rules stated for this exam.

#include "Runner.h"

Runner::Runner()
{
    firstname = "(default first name)";
    lastname = "(default last name)";
    pace = 0;
}
Runner::Runner(string First, string Last, int Pace)
{
    firstname = First;
    lastname = Last;
    pace = Pace;
}
string Runner::get_firstname()
{
    return firstname;
}
string Runner::get_lastname()
{
    return lastname;
}
int Runner::get_pace()
{
    return pace;
}

void set_firstname(string)
{
    
}
void set_lastname(string);
void set_pace(int);