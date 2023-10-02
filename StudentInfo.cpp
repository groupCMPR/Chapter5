//Names: Neidy Malaga & Vivian Huynh
//Date: 9/25/2023
//Description: Derived cpp file for class StudentInfo

#include "StudentInfo.h"

//---------------------------------------------------------------------------
//                               CONSTRUCTORS
//---------------------------------------------------------------------------
//Precondition : N/A
//Postcondition: Initalize the private members
StudentInfo::StudentInfo() : name("Unknown"), gradeLevel("Unknown"), gpa(0.0)
{}
//Precondition : N/A
//Postcondition: Change the private members
StudentInfo::StudentInfo(const string& new_Name, const string& level, const double& new_Gpa) : name(new_Name), gradeLevel(level), gpa(new_Gpa)
{}

//---------------------------------------------------------------------------
//                                ACCESSORS
//---------------------------------------------------------------------------
//Precondition : N/A
//Postcondition: Return the private member name
string StudentInfo::getName() const{
	return name;
}
//Precondition : N/A
//Postcondition: Return the private member gradeLevel to go into the classLevel
string StudentInfo::getGradeLevel() const{
	return gradeLevel;
}
//Precondition : N/A
//Postcondition: Return the private member gpa 
double StudentInfo::getGPA() const{
	return gpa;
}

//---------------------------------------------------------------------------
//                                MUTATORS
//---------------------------------------------------------------------------
//Precondition : Passing in newName in valid string inputs
//Postcondition: Changing private member name
void StudentInfo::setName(const string& newName){
	name = newName;
}
//Precondition : Passing in newGradeLevel between 0...4
//Postcondition: Changing private member gradeLevel
void StudentInfo::setGradeLevel(const string& newGradeLevel){
	gradeLevel = newGradeLevel;
}
//Precondition : Passing in newGpa between 0.0...4.0
//Postcondition: Changing private member gpa
void StudentInfo::setGPA(const double& newGpa){
	gpa = newGpa;
}

//---------------------------------------------------------------------------
//                                FRIENDS
//---------------------------------------------------------------------------
//overloading operator <<
//Precondition : Passing in out and valid obj of the class
//Postcondition: Outputting the display of student info (Name, Grade Level, GPA)
ostream& operator<<(ostream& outs, const StudentInfo& obj){
	outs << obj.getName() << ", " << obj.getGradeLevel() << ", " << obj.getGPA();
	return outs;
}
//overloading operator == 
//Precondition : Two StudentInfo classes 
//Postcondition: Returns true if all private members are same, else false
bool operator ==(const StudentInfo& obj1, const StudentInfo& obj2){
	if ((obj1.gpa == obj2.gpa) && (obj1.gradeLevel == obj2.gradeLevel) && (obj1.name == obj2.name))
		return true;
	else
		return false;
}
//overloading operator <
//Precondition : Two StudentInfo classes 
//Postcondition: Returns true if name in second object is first in order, else false
bool operator <(const StudentInfo& obj1, const StudentInfo& obj2){
	if (obj1.name < obj2.name)
		return true;
	else
		return false;
}
