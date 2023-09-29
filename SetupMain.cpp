//Names: Alexis Martinez, Angie Campos, Neidy Malaga, & Vivian Huynh
//Date: 9/25/2023
//Description: Chapter 5 Assignments: Vector and List Container

#include <iostream> //For cout
#include "input.h"  //For input validation
#include "Application.h"
//HEADER FILES
using namespace std;

//PROTOTYPES
int mainMenu();

//Option 1 - Vector Container
void vectorContainer();

//Option 2 - List Container
void listContainer();

//Option 3 - Application using Vector and/or List container
void vectorAndOrListContainer();

int main()
{
	do
	{
		system("cls");
		switch (mainMenu())
		{
		case 0: exit(0);
		case 1: system("cls"); vectorContainer(); break;
		case 2: system("cls"); listContainer(); break;
		case 3: system("cls"); vectorAndOrListContainer(); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}

int mainMenu()
{
	cout << "\n\t CMPR131 Chapter 5: Vector and List Container by Group 5 (Vivian Huynh) 9/25/2023";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Vector container";
	cout << "\n\t\t2> List container";
	cout << "\n\t\t3> Application using Vector and/or List container";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0. Exit";
	cout << "\n\t" << string(100, char(205));

	return inputInteger("\n\t\tOption: ", 0, 3);
}

//==================================================================================================================
// Option 1 - Vector container Section
//================================================================================================================== 
void vectorContainer()
{
	do
	{
		system("cls");
		cout << "\n\tVectors are sequence containers representing arrays that can change in size.\n";

		cout << "\n\t1> Vector's member functions";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)";
		cout << "\n\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements";
		cout << "\n\t\tC> resize(n) - Resizes the container so that it contains n elements";
		cout << "\n\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector";
		cout << "\n\t\tE> pop_back() - Removes the last element in the vector";
		cout << "\n\t\tF> front() - Returns a reference to the first element in the vector";
		cout << "\n\t\tG> back() - Returns a reference to the last element in the vector";
		cout << "\n\t\tH> index using at() or []) - Returns a reference to the element at position n in the vector";
		cout << "\n\t\tI> begin() - Returns an iterator pointing to the first element in the vector";
		cout << "\n\t\tJ> end() Returns an iterator referring to the past - the - end element in the vector";
		cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the vector";
		cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector";
		cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first";
		cout << "\n\t\t             element in the vector";
		cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the vector";
		cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
		cout << "\n\t\tP> erase(start_it, end_it) - Removes from the vector a range of elements(using iterators)";
		cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
		cout << "\n\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type";
		cout << "\n\t\tS> Sort - Sorts the vector.";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(100, char(205));

		switch (inputChar("\n\t\tOption: ", static_cast<string>("0ABCDEFGHIJKLMNOPQRS")))
		{
		case '0': return;
		case 'A': system("cls"); break;
		case 'B': system("cls"); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}

//==================================================================================================================
// Option 2 - List container Section
//================================================================================================================== 
void listContainer()
{
	do
	{
		system("cls");
		cout << "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the";
		cout << "\n\tsequence, and iteration in both directions.\n";

		cout << "\n\t2> List container";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\tA> clear() - Destroys all elements from the list";
		cout << "\n\t\tB> resize(n) - Changes the list so that it contains n elements";
		cout << "\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list";
		cout << "\n\t\tD> pop_front() - Deletes the first element";
		cout << "\n\t\tE> front() - Accesses the first element";
		cout << "\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list";
		cout << "\n\t\tG> pop_back() - Delete the last element";
		cout << "\n\t\tH> back() Accesses the last element";
		cout << "\n\t\tI> begin() - Returns an iterator refereing to the first element in the list";
		cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list";
		cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the list";
		cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list";
		cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element";
		cout << "\n\t\t            in the list";
		cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list";
		cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
		cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)";
		cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
		cout << "\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type";
		cout << "\n\t\tS> Sort - Sorts the list.";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(100, char(205));

		switch (inputChar("\n\t\tOption: ", static_cast<string>("0ABCDEFGHIJKLMNOPQRS")))
		{
		case '0': return;
		case 'A': system("cls"); break;
		case 'B': system("cls"); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}

//==================================================================================================================
// Option 3 - Application using Vector and/or List container Section
//================================================================================================================== 
void vectorAndOrListContainer()
{
	Application list_Apply;
	do
	{
		system("cls");
		cout << "\n\t3> Application using Vector and/or List container";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\tA> Add an integer";
		cout << "\n\t\tB> Delete an integer";
		cout << "\n\t\tC> Display input integers";
		cout << "\n\t\tD> Display frequencies of integers";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(100, char(205));

		switch (inputChar("\n\t\tOption: ", static_cast<string>("0ABCD")))
		{
		case '0': return;
		case 'A': list_Apply.set_List(inputInteger("\n\tAdd an integer: ")); break;
		case 'B': {
			int user_Value = inputInteger("\n\t Delete an integer: ");
			try{
				list_Apply.delete_List(user_Value);
			}
			catch (const invalid_argument& error){
				cout << "\n\t" << error.what() << to_string(user_Value) << ".";
			}
		}break;
		case 'C': { 
			if (list_Apply.get_Empty()) {
				cout << "\n\tERROR: Empty List. Please input integer (Option A)";
				break;
			}
			
			cout << list_Apply;
		}; break;
		case 'D': {
			if (list_Apply.get_Empty()) {
				cout << "\n\tERROR: Empty List. Please input integer (Option A)";
				break;
			}

			cout << list_Apply.get_Freq();
			}; break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}
