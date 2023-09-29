#include "StudentInfo.h"

const string classLevel[] = { "Unknown", "Freshman", "Sophmore", "Junior", "Senior" };

StudentInfo::StudentInfo() : name("Unknown"), gradeLevel(0), gpa(0.0)
{}

//ACCESSORS
string StudentInfo::getName() const
{
	return name;
}
string StudentInfo::getGradeLevel() const
{
	return classLevel[gradeLevel];
}
double StudentInfo::getGpa() const
{
	return gpa;
}

//MUTATORS
void StudentInfo::setName(string newName)
{
	name = newName;
}
void StudentInfo::setGradeLevel(int newGradeLevel)
{
	gradeLevel = newGradeLevel;
}
void StudentInfo::setGpa(double newGpa)
{
	gpa = newGpa;
}