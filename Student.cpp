//Names: Neidy Malaga, & Vivian Huynh
//Date: 9/25/2023
//Description: Derived cpp file for class StudentInfo

#include "student.h"

//Precondition : N/A
//Postcondition: Initalize the private members
student::student() : name("Unknown"), gradeLevel("Unknown"), GPA(0.0)
{}

student::student(const string& new_Name, const string& level, const double& new_Gpa) : name(new_Name), gradeLevel(level), GPA(new_Gpa)
{}

//============================================================
// Accessors Section
//============================================================
//Precondition : N/A
//Postcondition: Return the private member name
string student::getName() const
{
	return name;
}
//Precondition : N/A
//Postcondition: Return the private member gradeLevel to go into the classLevel
string student::getGradeLevel() const
{
	return gradeLevel;
}
//Precondition : N/A
//Postcondition: Return the private member gpa 
double student::getGPA() const
{
	return GPA;
}

//============================================================
// Mutators Section
//============================================================
//Precondition : Passing in newName in valid string inputs
//Postcondition: Changing private member name
void student::setName(const string& newName)
{
	name = newName;
}
//Precondition : Passing in newGradeLevel between 0...4
//Postcondition: Changing private member gradeLevel
void student::setGradeLevel(const string& newGradeLevel)
{
	gradeLevel = newGradeLevel;
}
//Precondition : Passing in newGpa between 0.0...4.0
//Postcondition: Changing private member gpa
void student::setGPA(const double& newGpa)
{
	GPA = newGpa;
}

//============================================================
// Friend Section
//============================================================
// overloading operator <<
//Precondition : Passing in out and valid obj of the class
//Postcondition: Outputting the display of student info (Name, Grade Level, GPA)
ostream& operator<<(ostream& outs, const student& obj)
{
	outs << obj.getName() << ", " << obj.getGradeLevel() << ", " << obj.getGPA();
	return outs;
}

//overloading operator == 
//Precondition : two StudentInfo classes 
//Postcondition: returns true if all private members are same, else false
bool operator ==(const student& obj1, const student& obj2)
{
	if ((obj1.GPA == obj2.GPA) && (obj1.gradeLevel == obj2.gradeLevel) && (obj1.name == obj2.name))
		return true;
	else
		return false;
}

//overloading operator <
//Precondition : two StudentInfo classes 
//Postcondition: returns true if name in second object is first in order, else false
bool operator <(const student& obj1, const student& obj2)
{
	if (obj1.name < obj2.name)
		return true;
	else
		return false;
}
