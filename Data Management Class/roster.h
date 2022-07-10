#include <iostream>
#include "student.h"
#pragma once
#include <string>
#include <vector>
#include <array>

class Roster

{
public:
    int lastIndex = -1;
    const static int numOfStudents = 5;
    Student* classRosterArray[numOfStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    
public:
    
    void parse(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram dp);
    void removeStudentWithID(string studentID);
    void printAll();
    void printAverageDaysInCourse(string daysToComplete);
    void printInvalidEmails();
    void printbyDegreeprogram(DegreeProgram dp);
    
};


