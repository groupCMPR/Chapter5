//Names: Neidy Malaga, & Vivian Huynh
//Date: 9/25/2023
//Description: Derived cpp file for class StudentInfo

#include "StudentInfo.h"

const string classLevel[] = { "Unknown", "Freshman", "Sophmore", "Junior", "Senior" };

//Precondition : N/A
//Postcondition: Initalize the private members
StudentInfo::StudentInfo() : name("Unknown"), gradeLevel(0), gpa(0.0)
{}

StudentInfo::StudentInfo(const string& new_Name, const int& level, const double& new_Gpa) : name(new_Name), gradeLevel(level), gpa(new_Gpa)
{}

//============================================================
// Accessors Section
//============================================================
//Precondition : N/A
//Postcondition: Return the private member name
string StudentInfo::getName() const
{
	return name;
}
//Precondition : N/A
//Postcondition: Return the private member gradeLevel to go into the classLevel
string StudentInfo::getGradeLevel() const
{
	return classLevel[gradeLevel];
}
//Precondition : N/A
//Postcondition: Return the private member gpa 
double StudentInfo::getGpa() const
{
	return gpa;
}

//============================================================
// Mutators Section
//============================================================
//Precondition : Passing in newName in valid string inputs
//Postcondition: Changing private member name
void StudentInfo::setName(string newName)
{
	name = newName;
}
//Precondition : Passing in newGradeLevel between 0...4
//Postcondition: Changing private member gradeLevel
void StudentInfo::setGradeLevel(int newGradeLevel)
{
	gradeLevel = newGradeLevel;
}
//Precondition : Passing in newGpa between 0.0...4.0
//Postcondition: Changing private member gpa
void StudentInfo::setGpa(double newGpa)
{
	gpa = newGpa;
}

//============================================================
// Friend Section
//============================================================
//Precondition : Passing in out and valid obj of the class
//Postcondition: Outputting the display of student info (Name, Grade Level, GPA)
ostream& operator<<(ostream& out, const StudentInfo& obj)
{
	out << obj.getName() << ", " << obj.getGradeLevel() << ", " << obj.getGpa();
	return out;
}
