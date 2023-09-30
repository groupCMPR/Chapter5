#pragma once
//Names: Neidy Malaga, & Vivian Huynh
//Date: 9/25/2023
//Description: Header file for class ListContainer
//IF YOU ARE HAVING TROUBLE UNDERSTANDING PLEASE READ MY DESCRIPTION OF COMPOSITION NEAR STUDENT LIST PRIVATE MEMBER INITIALIZATION, IS SHOULD CLEAR SOME THINGS UP
#pragma once
#include "StudentInfo.h"
#include<iostream>
#include <string>
#include <sstream> //for displaying data types
#include <list>

using namespace std;

class ListContainer{
private:
	list <StudentInfo> Student_List; // Composition, is a list of StudentInfo's objects
	//allows you to change elements (by either passing a StudentInfo constructor or obj)
	//allows you to display elements: iter->get_ or *iter (which will display overloaded << function of studentInfo)


public:
	//CONSTRUCTOR
	ListContainer();


	//MUTATORS
	void set_Clear();
	void set_Resize(const int&);
	void set_List(const StudentInfo&, const bool&);
	void set_Pop_Front();
	void set_Pop_Back();
	void erase(const int&);
	void erase(const int&, const int&);
	void insert(const int&, const int&);
	void swap();
	void sort();

	//ACCESSORS
	size_t get_Size() const;
	string get_Front() const;
	string get_Back() const;
	bool get_Empty() const;
	list<StudentInfo>::const_iterator  get_First_Iter() const;

	friend ostream& operator<<(ostream&, const ListContainer&);
};
