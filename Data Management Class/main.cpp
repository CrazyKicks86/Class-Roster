#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

#define main_c

using namespace std;

int main ()
{
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 
        "A5,Josh,Kinard,jkina20@wgu.edu,35,12,26,31,SOFTWARE"
    };
    
    cout << "C867 Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Josh Kinard" << endl;
    cout << "Student ID: 009460710" << endl << endl;
    
    const int GivenStudentData = 5;
    Roster *roster = new Roster;

    for (int i = 0; i < GivenStudentData; i++) roster->parse(studentData[i]);
    cout << "--Display All Students--"  <<endl;
    roster->printAll(); cout << "" "" << endl;
    
    cout << "--Display All Invalid Email Address's--" << endl;
    roster->printInvalidEmails(); cout << " " << endl;
    
    cout << "--Display Average Days In Course By Student ID--"  << endl;
    for (int i = 0; i < GivenStudentData; i++)
    roster->printAverageDaysInCourse(roster->classRosterArray[i]->getstudentID()); cout << " " << endl;
    
    cout << "--Display Software Students--" << endl;
    roster->printbyDegreeprogram(Software); cout << " " << endl;
    
    cout << "--Remove Student A3--" << endl;
    roster->removeStudentWithID("A3"); cout << " " << endl;
    
    cout << "--Show All Students--" << endl;
    roster->printAll(); cout << " " << endl;
    
    cout << "--Student A3 does not exist--" << endl;
    roster->removeStudentWithID("A3"); cout << " " << endl;
    
    roster->~Roster();
    cout << "--Roster Memory Released--" << endl;
};
