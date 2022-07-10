#include <iostream>
#include "roster.h"
#include <string>

using namespace std;
   

void Roster::parse(string row)
    {
        vector<string> result;
        size_t start;
        size_t end = 0;
        while ((start = row.find_first_not_of(',', end)) != string::npos)
        {
            end = row.find(',', start);
            result.push_back(row.substr(start, end - start));
        }
        DegreeProgram dp = DegreeProgram::Unknown;  //Default//
        switch (result.at(8).back())
        {
            case 'Y': dp = DegreeProgram::Security; break;
            case 'E': dp = DegreeProgram::Software; break;
            case 'K': dp = DegreeProgram::Network; break;
        }
    add(result.at(0), result.at(1), result.at(2), result.at(3), stod(result.at(4)), stod(result.at(5)), stod(result.at(6)), stod(result.at(7)), dp);
    }

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram)
    
    {  
        int daysToCompleteArray[3] = {daysToComplete1, daysToComplete2, daysToComplete3};
        
        classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteArray, degreeProgram);
    }
                          
void Roster::removeStudentWithID(string studentID)
    {
        bool success = false;
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            if (classRosterArray[i]->getstudentID() == studentID)
            {
                success = true;
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numOfStudents - 1];
                classRosterArray[numOfStudents - 1] = temp;
                Roster::lastIndex--;
            }
        }
            if (success)
            {
                cout << "--Student " << studentID << " has been removed.--" << endl;
                
            }
           
    }
                          
void Roster::printAll()
    {
        Student::printdHeader();
        for (int i = 0; i <= Roster::lastIndex; i++)
            Roster::classRosterArray[i]->print();
    }

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getstudentID() == studentID)
        {
            cout << studentID << ": ";
            cout << (classRosterArray[i]->getdaysRemaining()[0] +
                     classRosterArray[i]->getdaysRemaining()[1] +
                     classRosterArray[i]->getdaysRemaining()[2]) / 3
            << endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    for (int i = 0; i < lastIndex; ++i) {
        string emailAddress = classRosterArray[i]->getemailAddress();
        if ((emailAddress.find(' ') != string::npos) || (emailAddress.find('.') == string::npos) || (emailAddress.find('@') == string::npos)) {
            cout << classRosterArray[i]->getstudentID() <<  ": " << emailAddress << " " << endl;
        }
    }
            cout << endl;
                return;
}
void Roster::printbyDegreeprogram(DegreeProgram dp)
    {
        Student::printdHeader();
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
        }
            cout <<std::endl;
    };
