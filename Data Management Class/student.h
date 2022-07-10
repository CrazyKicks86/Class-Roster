#pragma once
#include <iostream>
#include "degree.h"
#include <iomanip>

using std::cout;
using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;


class Student

{

public:
    const static int daysToCompleteArray = 3;

private:
    string StudentID;
    string FirstName;
    string LastName;
    string EmailAddress;
    int Age;
    int daysRemaining[daysToCompleteArray];
    DegreeProgram degreeprogram;

public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysRemaining[], DegreeProgram degreeProgram);
    ~Student();
    
    //Accessors//
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemailAddress();
    int getage();
    int* getdaysRemaining();
    DegreeProgram getDegreeProgram();
    
    //Mutators//
    void setstudentID(string studentID);
    void setfirstName(string firstName);
    void setlastName(string lastName);
    void setemailAddress(string emailAddress);
    void setage(int age);
    void setdaysRemaining(int daysToComplete[]);
    void setDegreeProgram(DegreeProgram dp);
    
    static void printdHeader();
    
    void print();
    
};
