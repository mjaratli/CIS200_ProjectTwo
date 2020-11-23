#define _CRT_SECURE_NO_WARNINGS
#define NEWLINE '\n'
#include "ToDoList.h"
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

int main()
{
	//Creating the ToDoList Array
	ToDoList list_one;

	int menuChoice;
	do {
		cout << NEWLINE << NEWLINE;
		cout << "This is the menu for your to-do list";
		cout << NEWLINE << NEWLINE;
		cout << "**************************************************************************************";
		cout << NEWLINE << NEWLINE;
		cout << "If you would like to exit press : 0" << NEWLINE;
		cout << "If you would like to add a to-do item press : 1" << NEWLINE;
		cout << "If you would like to edit a to-do item press : 2" << NEWLINE;
		cout << "If you would like to delete a to-do item by id press : 3" << NEWLINE;
		cout << "If you would like to delete to-do items by type press : 4" << NEWLINE;
		cout << "If you would like to delete to-do items by status press : 5" << NEWLINE;
		cout << "If you would like to write your list to a txt file press : 6" << NEWLINE;
		cout << "If you would like to read to-do items from the txt file press : 7" << NEWLINE;
		cout << "If you would like to sort your to-do items press : 8" << NEWLINE;
		cout << "If you would like to choose how to print to the console press : 9" << NEWLINE;
		cout << "If you would like to merge the to-do items from the file press : 10" << NEWLINE;
	
		//Printing the menu
		list_one.printTestingThings();

		cin >> menuChoice;
		if (menuChoice == 1)
		{
			//TITLE
			string title;
			cout << "Please add the title" << NEWLINE;
			cin.ignore();
			getline(cin, title);
			cout << NEWLINE;
			//TYPE
			int userInput;
			cout << "Enter the type of work by integer : Shopping = 0, Housing = 1, Work = 2" << NEWLINE;
			cin >> userInput;
			cout << NEWLINE;
			type usertype = static_cast<type>(userInput);
			/*
			* Had to switch type and description input order
			* because getline() and cin.ignore() was skipping the
			* first character in description
			*/
			//DESCRIPTION
			string description;
			cout << "Please add the description" << NEWLINE;
			cin.ignore();
			getline(cin, description);
			cout << NEWLINE;
			//PRIORITY
			int priority;
			cout << "Enter the priority if your to-do item : 1 through 5" << NEWLINE;
			cin >> priority;
			cout << NEWLINE;
			//STATUS
			int userInputStatus;
			cout << "Enter the status by integer : Done = 0, InProgress = 1, Hold = 2" << NEWLINE;
			cin >> userInputStatus;
			cout << NEWLINE;
			status userstatus = static_cast<status>(userInputStatus);
			//Create Date - by program 

			//DUE DATE
			int month;
			int day;
			int year;
			cout << "Please enter the month, day, and year for the due date like so : MM DD YYYY" << NEWLINE;
			cin >> month >> day >> year;

			//Last Modified Date - by program 

			//FUNCTION CALL 
			list_one.addItem(title, description, usertype, priority, userstatus, month, day, year);

		}
		else if (menuChoice == 2)
		{
			int id;
			cout << "Please enter the Id of the item you would like to edit" << NEWLINE;
			cin >> id;
			cout << NEWLINE;
			cout << "To edit the title press : 0" << NEWLINE;
			cout << "To edit the description press : 1" << NEWLINE;
			cout << "To edit the type press : 2" << NEWLINE;
			cout << "To edit the priority press : 3" << NEWLINE;
			cout << "To edit the status press : 4" << NEWLINE;
			cout << "To edit the due date press : 5" << NEWLINE;
			int editNum;
			cin >> editNum;
			list_one.editItemId(id, editNum);
		}
		else if (menuChoice == 3)
		{
			int idNum;
			cout << "Please enter the id of the item you would like to delete" << NEWLINE;
			cin >> idNum;
			list_one.deleteItemId(idNum);
		}
		else if (menuChoice == 4)
		{
			list_one.deleteItemType();
		}
		else if (menuChoice == 5)
		{
			list_one.deleteItemStatus();
		}
		else if (menuChoice == 6)
		{
			list_one.writeToFile();
		}
		else if (menuChoice == 7)
		{
			list_one.readFromFile();
		}
		else if (menuChoice == 8)
		{
			int sort;
			cout << "If you would like to sort your to-do items by priority press : 1" << NEWLINE;
			cout << "If you would like to sort your to-do items by due date press : 2" << NEWLINE;
			cout << "If you would like to sort your to-do items by create date press : 3" << NEWLINE;
			cin >> sort;
			if (sort == 1)
			{
				list_one.sortByPriority();
			}
			if (sort == 2)
			{
				list_one.sortByDueDate();
			}
			if (sort == 3)
			{
				list_one.sortCreateDate();
			}
		}
		else if (menuChoice == 9)
		{
			int print;
			cout << "If you would like to print all your items press : 1" << NEWLINE;
			cout << "If you would like to print by type press : 2" << NEWLINE;
			cout << "If you would like to print by priority : 3" << NEWLINE;
			cout << "If you would like to print by id press : 4" << NEWLINE;
			cin >> print;
			if (print == 1)
			{
				list_one.printTestingThings();
			}
			if (print == 2)
			{

				string typeOfString;
				int inputNumberType;
				cout << "Enter the type of work by integer : Shopping = 0, Housing = 1, Work = 2" << NEWLINE;
				cin >> inputNumberType;
				if (inputNumberType == 0)
				{
					typeOfString = "Shopping";
				}
				if (inputNumberType == 1)
				{
					typeOfString = "Housing";
				}
				if (inputNumberType == 2)
				{
					typeOfString = "Work";
				}
				//Print function
			list_one.printByType(typeOfString);
			}
			if (print == 3)
			{
				int priorityNum;
				cout << "Please enter the priority you would like to print : 1 to 5" << NEWLINE;
				cin >> priorityNum;
				//Print function
				list_one.printByPriority(priorityNum);
			}
			if (print == 4)
			{
				int idNumInput;
				cout << "Please enter the id number of the item you would like to print" << NEWLINE;
				cin >> idNumInput;
				//Print function 
				list_one.printById(idNumInput);
			}
		}
		else if (menuChoice == 10)
			{
			ToDoList list_two;
			list_two.readFromFile();
			list_one.merge(list_two);
			}

		else if (menuChoice != 0 && menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4 && menuChoice != 5 && menuChoice != 6 && menuChoice != 7
			&& menuChoice != 8 && menuChoice != 9)
		{
			cout << "Invalid input" << NEWLINE;
		}
	} while (menuChoice != 0);

	list_one.printTestingThings();


	return 0;
}