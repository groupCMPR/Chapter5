#pragma once
#include <list> //for list
#include <map> //for maps, used in frequencies
#include <iostream> //for overloaded function
#include <sstream> //for displaying data types, used in frequencies
#include <string> //for string
using namespace std;

class Application {
private:
	typedef int value_type;
	list<value_type> user_val_list;

public:
	//Default constructor
	Application(); 

	//MUTATOR:
	void set_List(const value_type&);
	void delete_List(const value_type&);

	//ACCESSOR:
	bool get_Empty() const;
	string get_Freq() const;

	friend ostream& operator <<(ostream& out, const Application &);
};
