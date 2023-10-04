//Names: Neidy Malaga
//Date: 9/28/2023
//Description: cpp file for class Application

#include "Application.h"

//Precondition : N/A
//Postcondition: N/A
Application::Application() {}

//---------------------------------------------------------------------------
//                                MUTATORS
//---------------------------------------------------------------------------
//Precondition : Integer new_Value
//Postcondition: Pushes in typedef value into back of list
void Application::set_List(const value_type& new_Val) {
	user_val_list.push_back(new_Val);
}
//Precondition : Integer user_Val
//Postcondition: Either returns if element is not in list, or erases it
void Application::delete_List(const value_type& user_Val) {
	list<value_type>::iterator find_element = find(user_val_list.begin(), user_val_list.end(), user_Val);

	if (find_element == user_val_list.end()) {
		throw invalid_argument("list does not contain");
	}

	user_val_list.erase(find_element);
}

//---------------------------------------------------------------------------
//                                ACCESSORS
//---------------------------------------------------------------------------
//Precondition : N/A
//Postcondition: Returns true if list is empty, else false
bool Application::get_Empty() const {
	return (user_val_list.empty());
}
//Precondition : Class must be filled in
//Postcondition: Returns string showing frequencies of each number
string Application::get_Freq() const {
	ostringstream ostream;
	map<value_type, int> Sorted_Map;
	ostream << "\n\tcontainer:";

	for (auto begin = user_val_list.begin(); begin != user_val_list.end(); ++begin) {
		++Sorted_Map[(*begin)];
	}

	for (auto begin = Sorted_Map.begin(); begin != Sorted_Map.end(); ++begin) {
		ostream << "\n\t" << begin->first << ": " << begin->second;
	}

	return ostream.str();
}
//Precondition : ostream, and class object, list must not be empty
//Postcondition: Returns an ostream for display
ostream& operator <<(ostream& out, const Application& obj) {
	out << "\n\tcontainer: ";

	for (auto begin = obj.user_val_list.begin(); begin != obj.user_val_list.end(); ++begin) {
		out << (*begin) << " ";
	}

	return out;
}
