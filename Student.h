#pragma once
#include <string>
#include <iostream>
using namespace std;

class student
{
private:
	string name;    //To contain the student name
	string gradeLevel; //To contain the grade level
	double GPA;     //To contain the student's gpa

public:
	//CONSTRUCTOR
	student();
	student(const string&, const string&, const double&);

	//ACCESSORS
	string getName() const;
	string getGradeLevel() const;
	double getGPA() const;

	//MUTATORS
	void setName(const string&);
	void setGradeLevel(const string&);
	void setGPA(const double&);

	//FRIEND
	friend ostream& operator<<(ostream&, const student&);
	friend bool operator ==(const student&, const student&);
	friend bool operator <(const student&, const student&);

};
