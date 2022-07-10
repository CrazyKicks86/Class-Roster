#include <iostream>
#include "student.h"
#include <string>


using namespace std;

Student::Student()  //Default Constructor//
{
    this->StudentID = "";
    this->FirstName = "";
    this->LastName = "";
    this->EmailAddress = "";
    this->Age = 0;
    for (int i = 0; i < daysToCompleteArray; i++)
        this->daysRemaining[i] = 0;
    this->degreeprogram = DegreeProgram::Unknown;
    
}

Student::Student  //Main Constructor//
(string studentID, string firstName, string lastName, string emailAddress, int age, int daysRemaining[], DegreeProgram degreeProgram)
{
    this->StudentID = studentID;
    this->FirstName = firstName;
    this->LastName = lastName;
    this->EmailAddress = emailAddress;
    this->Age = age;
    for (int i = 0; i < daysToCompleteArray; i++)
        this->daysRemaining[i] = daysRemaining[i];
    this->degreeprogram = degreeProgram;
}

Student::~Student() {}

//Accessors//Getters//

string Student::getstudentID()
    { return this->StudentID; }

string Student::getfirstName()
    { return this->FirstName; }

string Student::getlastName()
    { return this->LastName; }

string Student::getemailAddress()
    { return this->EmailAddress; }

int Student::getage()
    { return this->Age; }

int* Student::getdaysRemaining()
    { return this->daysRemaining; }

DegreeProgram Student::getDegreeProgram()
    { return this->degreeprogram; }


 //Mutators//Setters//

void Student::setstudentID(string studentID) { this->StudentID = studentID; }
void Student::setfirstName(string firstName) { this->FirstName = firstName; }
void Student::setlastName(string lastName) { this->LastName = lastName; }
void Student::setemailAddress(string emailAddress) { this->EmailAddress = emailAddress; }
void Student::setage(int Age) { this->Age = Age; }
void Student::setdaysRemaining(int daysToComplete[])
{
    for (int i = 0; i < daysToCompleteArray; i++) this->daysRemaining[i] = daysRemaining[i];
}
void Student::setDegreeProgram(DegreeProgram dp) {this->degreeprogram = dp; }

void Student::printdHeader()

{
    cout << "SID\t";
    cout << "FirstN\t";
    cout << "LastN\t";
    cout << "Email\t";
    cout << "Age\t\t";
    cout << "AVG Days In Course (1,2,3)\t";
    cout << "Degree Program\t";
    cout << endl;
}

void Student::print()
{
    cout << this->StudentID             << "\t";
    cout << this->FirstName             << "\t";
    cout << this->LastName              << "\t";
    cout << this->EmailAddress          << "\t\t";
    cout << this->Age                   << "\t\t";
    cout << this->daysRemaining[0]      << ',';
    cout << this->daysRemaining[1]      << ',';
    cout << this->daysRemaining[2]      << '\t';
    cout << degreeProgramStrings[(int)this->degreeprogram];
    cout << endl;
    
}



