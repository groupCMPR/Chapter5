//Names: Neidy Malaga
//Date: 9/28/2023
//Description: Header file for class Application

#pragma once
#include <list>     //For list
#include <map>      //For maps, used in frequencies
#include <iostream> //For overloaded function
#include <sstream>  //For displaying data types, used in frequencies
#include <algorithm> //for find
#include <string>   //For string
using namespace std;

class Application {
private:
	typedef int value_type;
	list<value_type> user_val_list;

public:
	//CONSTRUCTOR
	Application(); //Default

	//MUTATORS
	void set_List(const value_type&);
	void delete_List(const value_type&);

	//ACCESSORS
	bool get_Empty() const;
	string get_Freq() const;

	//FRIEND
	friend ostream& operator <<(ostream& out, const Application&);
};
