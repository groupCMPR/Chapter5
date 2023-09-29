//Names: Neidy Malaga, & Vivian Huynh
//Date: 9/25/2023
//Description: Header file for class ListContainer

#pragma once
#include <string>
#include <list>
using namespace std;

class ListContainer
{
private:
	

public:
	//CONSTRUCTOR
	ListContainer();

	//ACCESSORS
	//back(); //Maybe?
	//begin();
	//end();
	//rbegin();
	//rend();

	//MUTATORS
	void clear();
	void resize(int);
	void pop_front();
	void erase(int);
	void erase(int, int);
	void insert(int, int);
	void swap();
	void sort();
};
