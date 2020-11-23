#define _CRT_SECURE_NO_WARNINGS
#include "ToDoList.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#define NEWLINE '\n'
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::atoi;
using namespace std;
//using std::stoi;
using std::fstream;
using std::ifstream;
using std::ofstream;

int positionOfItems = 0;

//Regular constructor
ToDoList::ToDoList()
{
	headPtr = nullptr;
}

//Copy constructor 
void ToDoList::deepCopy(list* old_linked_list, list*& new_linked_list)
{
	list* traverse_old = old_linked_list;
	new_linked_list = new list;
	list* traverse_new = new_linked_list;
	while (traverse_old != nullptr)
	{
		traverse_new->item = traverse_old->item;
		traverse_new->next = new list;
		traverse_old = traverse_old->next;
		traverse_new = traverse_new->next;
		traverse_new->next = nullptr;
	}
}

//Merge function
void ToDoList::merge(ToDoList& rhs)
{
	list* traverse = this->headPtr;
	while (true)
	{		
		if (traverse->next == nullptr)
		{
			traverse->next = rhs.headPtr;
			break;
		}
		traverse = traverse->next;
	}
	refreshItemId();
}

//Printing functions
void ToDoList::printTestingThings()
{
	if (headPtr == nullptr)
	{
		cout << NEWLINE << "You currently have 0 to-do items" << NEWLINE;
	}
	else
	{
		//Printing the "Menu"
		cout << NEWLINE << NEWLINE;
		cout << left << setw(3) << "ID" << "|"
			<< left << setw(15) << "Title" << "|"
			<< left << setw(30) << "Description" << "|"
			<< left << setw(10) << "Type" << "|"
			<< left << setw(10) << "Priority" << "|"
			<< left << setw(12) << "Status" << "|"
			<< left << setw(11) << "Create Date" << "|"
			<< left << setw(11) << "Due Date" << "|"
			<< left << setw(11) << "Last Modified Date";
		cout << NEWLINE << NEWLINE;
		list* traverse;
		traverse = headPtr;
		while (traverse != nullptr)
		{
			//Id
			cout << left << setw(3) << traverse->item.getId() << "|"
				<< left << setw(15) << traverse->item.getTitle() << "|"
				<< left << setw(30) << traverse->item.getDescription() << "|"
				<< left << setw(10) << traverse->item.getType() << "|"
				<< left << setw(10) << traverse->item.getPriority() << "|"
				<< left << setw(12) << traverse->item.getStatus() << "|"
				<< left << setw(3) << traverse->item.getCreateDate().month << left << setw(3) << traverse->item.getCreateDate().day << left << setw(5) << traverse->item.getCreateDate().year << "|"
				<< left << setw(3) << traverse->item.getDueDate().month << left << setw(3) << traverse->item.getDueDate().day << left << setw(5) << traverse->item.getDueDate().year << "|"
				<< left << setw(3) << traverse->item.getModifiedDate().month << left << setw(3) << traverse->item.getModifiedDate().day << left << setw(5) << traverse->item.getModifiedDate().year;
			cout << endl;
			traverse = traverse->next;
		}
	}
}

void ToDoList::printByType(string t)
{
	if (headPtr == nullptr)
	{
		cout << NEWLINE << "You currently have 0 to-do items" << NEWLINE;
	}
	else {
		//Printing the "Menu"
		cout << NEWLINE << NEWLINE;
		cout << left << setw(3) << "ID" << "|"
			<< left << setw(15) << "Title" << "|"
			<< left << setw(30) << "Description" << "|"
			<< left << setw(10) << "Type" << "|"
			<< left << setw(10) << "Priority" << "|"
			<< left << setw(12) << "Status" << "|"
			<< left << setw(11) << "Create Date" << "|"
			<< left << setw(11) << "Due Date" << "|"
			<< left << setw(11) << "Last Modified Date";
		cout << NEWLINE << NEWLINE;

		list* traverse;
		traverse = headPtr;
		while (traverse != nullptr)
		{
			if (traverse->item.getType().compare(t) == 0) {
				cout << left << setw(3) << traverse->item.getId() << "|"
					<< left << setw(15) << traverse->item.getTitle() << "|"
					<< left << setw(30) << traverse->item.getDescription() << "|"
					<< left << setw(10) << traverse->item.getType() << "|"
					<< left << setw(10) << traverse->item.getPriority() << "|"
					<< left << setw(12) << traverse->item.getStatus() << "|"
					<< left << setw(3) << traverse->item.getCreateDate().month << left << setw(3) << traverse->item.getCreateDate().day << left << setw(5) << traverse->item.getCreateDate().year << "|"
					<< left << setw(3) << traverse->item.getDueDate().month << left << setw(3) << traverse->item.getDueDate().day << left << setw(5) << traverse->item.getDueDate().year << "|"
					<< left << setw(3) << traverse->item.getModifiedDate().month << left << setw(3) << traverse->item.getModifiedDate().day << left << setw(5) << traverse->item.getModifiedDate().year;
				cout << endl;
			}
			traverse = traverse->next;
		}
	}
	//cout << endl;
}

void ToDoList::printByPriority(int pNum)
{
	if (headPtr == nullptr)
	{
		cout << NEWLINE << "You currently have 0 to-do items" << NEWLINE;
	}
	else {
		//Printing the "Menu"
		cout << NEWLINE << NEWLINE;
		cout << left << setw(3) << "ID" << "|"
			<< left << setw(15) << "Title" << "|"
			<< left << setw(30) << "Description" << "|"
			<< left << setw(10) << "Type" << "|"
			<< left << setw(10) << "Priority" << "|"
			<< left << setw(12) << "Status" << "|"
			<< left << setw(11) << "Create Date" << "|"
			<< left << setw(11) << "Due Date" << "|"
			<< left << setw(11) << "Last Modified Date";
		cout << NEWLINE << NEWLINE;

		list* traverse;
		traverse = headPtr;
		while (traverse != nullptr)
		{
			if (traverse->item.getPriority() == pNum) 
			{
				cout << left << setw(3) << traverse->item.getId() << "|"
					<< left << setw(15) << traverse->item.getTitle() << "|"
					<< left << setw(30) << traverse->item.getDescription() << "|"
					<< left << setw(10) << traverse->item.getType() << "|"
					<< left << setw(10) << traverse->item.getPriority() << "|"
					<< left << setw(12) << traverse->item.getStatus() << "|"
					<< left << setw(3) << traverse->item.getCreateDate().month << left << setw(3) << traverse->item.getCreateDate().day << left << setw(5) << traverse->item.getCreateDate().year << "|"
					<< left << setw(3) << traverse->item.getDueDate().month << left << setw(3) << traverse->item.getDueDate().day << left << setw(5) << traverse->item.getDueDate().year << "|"
					<< left << setw(3) << traverse->item.getModifiedDate().month << left << setw(3) << traverse->item.getModifiedDate().day << left << setw(5) << traverse->item.getModifiedDate().year;
				cout << endl;
			}

			traverse = traverse->next;
		}
				
	}
	//cout << endl;
}

void ToDoList::printById(int idNum)
{
	if (headPtr == nullptr)
	{
		cout << NEWLINE << "You currently have 0 to-do items" << NEWLINE;
	}
	else {
		//Printing the "Menu"
		cout << NEWLINE << NEWLINE;
		cout << left << setw(3) << "ID" << "|"
			<< left << setw(15) << "Title" << "|"
			<< left << setw(30) << "Description" << "|"
			<< left << setw(10) << "Type" << "|"
			<< left << setw(10) << "Priority" << "|"
			<< left << setw(12) << "Status" << "|"
			<< left << setw(11) << "Create Date" << "|"
			<< left << setw(11) << "Due Date" << "|"
			<< left << setw(11) << "Last Modified Date";
		cout << NEWLINE << NEWLINE;

		list* traverse;
		traverse = headPtr;
		while (traverse != nullptr)
		{
			if (traverse->item.getId() == idNum)
			{
				cout << left << setw(3) << traverse->item.getId() << "|"
					<< left << setw(15) << traverse->item.getTitle() << "|"
					<< left << setw(30) << traverse->item.getDescription() << "|"
					<< left << setw(10) << traverse->item.getType() << "|"
					<< left << setw(10) << traverse->item.getPriority() << "|"
					<< left << setw(12) << traverse->item.getStatus() << "|"
					<< left << setw(3) << traverse->item.getCreateDate().month << left << setw(3) << traverse->item.getCreateDate().day << left << setw(5) << traverse->item.getCreateDate().year << "|"
					<< left << setw(3) << traverse->item.getDueDate().month << left << setw(3) << traverse->item.getDueDate().day << left << setw(5) << traverse->item.getDueDate().year << "|"
					<< left << setw(3) << traverse->item.getModifiedDate().month << left << setw(3) << traverse->item.getModifiedDate().day << left << setw(5) << traverse->item.getModifiedDate().year;
				cout << endl;
			}

			traverse = traverse->next;
		}

	}
	//cout << endl;
}

/*
* Ask the user to enter the attributes
* for to-do item and then insert the to-do item
* to the bottom of the list
*/
void ToDoList::addItem(string title, string description, type t, int priority, status s, int month, int day, int year)
{
	ToDo addedItem;
	//ID
	addedItem.setId(positionOfItems);
	//Title
	addedItem.setTitle(title);
	//Description
	addedItem.setDescription(description);
	//Type
	addedItem.setType(t);
	//Priority
	addedItem.setPriority(priority);
	//Status
	addedItem.setStatus(s);;
	//Create date - no user input
	addedItem.setCreateDate();
	//Due date
	addedItem.setDueDate(month,day,year);
	//Last modified date - no user input
	addedItem.setModifiedDate();
	//Adding the item to the end of the linked list
	list* new_node = new list;
	list* traverse = headPtr;
	new_node->item = addedItem;
	new_node->next = nullptr;
	if (headPtr == nullptr)
	{
		headPtr = new_node;
	}
	else {
		while (traverse->next != nullptr)
		{
			traverse = traverse->next;
		}
		traverse->next = new_node;
	}
	positionOfItems++;
}

/*
* Ask the user which attribute
* to edit and then makes the change
* to the chosen existing to-do item
*/
void ToDoList::editItemId(int id, int edit)
{
	list* traverse = headPtr;
	while (traverse != nullptr)
	{
		if (traverse->item.getId() == id)
		{
			if (edit == 0)
			{
				//Title
				string title;
				cout << "Please enter the new title" << NEWLINE;
				cin.ignore();
				getline(cin, title);
				traverse->item.setTitle(title);
				//Last modified date - no user input
				traverse->item.setModifiedDate();
			}
			else if (edit == 1)
			{
				//Description
				string description;
				cout << "Please enter the new description" << NEWLINE;
				cin.ignore();
				getline(cin, description);
				traverse->item.setDescription(description);
				//Last modified date - no user input
				traverse->item.setModifiedDate();
			}
			else if (edit == 2)
			{
				//Type
				int userInput;
				cout << "Enter the type of work by integer : Shopping = 0, Housing = 1, Work = 2" << NEWLINE;
				cin >> userInput;
				cout << NEWLINE;
				type usertype = static_cast<type>(userInput);
				traverse->item.setType(usertype);
				//Last modified date - no user input
				traverse->item.setModifiedDate();
			}
			else if (edit == 3)
			{
				//Priority
				int priority;
				cout << "Please enter the priority number 1 through 5" << NEWLINE;
				cin >> priority;
				traverse->item.setPriority(priority);
				//Last modified date - no user input
				traverse->item.setModifiedDate();
			}
			else if (edit == 4)
			{
				//Status
				int userInput;
				cout << "Enter the status by integer : Done = 0, InProgress = 1, Hold = 2" << NEWLINE;
				cin >> userInput;
				cout << NEWLINE;
				status userstatus = static_cast<status>(userInput);
				traverse->item.setStatus(userstatus);
				//Last modified date - no user input
				traverse->item.setModifiedDate();
			}
			else if (edit == 5)
			{
				//Due date
				int month;
				int day;
				int year;
				cout << "Please enter the month, day, and year for the due date like so : MM DD YYYY" << NEWLINE;
				cin >> month >> day >> year;
				traverse->item.setDueDate(month, day, year);
				//Last modified date - no user input
				traverse->item.setModifiedDate();
			}
			else if (edit != 0 && edit != 1 && edit != 2 && edit != 3 && edit != 4 && edit != 5)
			{
				cout << "Invalid input : You tried to change a non-existing attribute" << NEWLINE;
			}
			else
			{
			cout << "Invalid input : You tried to choose from a non-existing id" << NEWLINE;
			}
		}
		//Iterating through the linked list
		traverse = traverse->next;
	}
}

void ToDoList::refreshItemId()
{
	list* traverse = headPtr;
	int count = 0;
	while (traverse != nullptr)
	{
		traverse->item.setId(count);
		traverse = traverse->next;
		count++;
	}
}

void ToDoList::deleteItemId(int id)
{
	int count = 0;
	list* prevPtr = headPtr;
	if (id == 0)
	{
		headPtr = headPtr->next;
		//OR headPtr = prevPtr->next;
		delete prevPtr;
	}
	else {
		for (int i = 0; i < id - 1; i++)
		{
			prevPtr = prevPtr->next;
		}
		list* currPtr = prevPtr->next;
		if (currPtr == nullptr)
		{
			prevPtr = nullptr;
			delete prevPtr;
			delete currPtr;
		}
		else 
		{
			prevPtr->next = currPtr->next;
		}
		delete currPtr;
	}
	refreshItemId();
	positionOfItems--;

}


void ToDoList::deleteItemType()
{
	//Type
	int userInput;
	cout << "Enter the type you would like to delete : Shopping = 0, Housing = 1, Work = 2" << NEWLINE;
	cin >> userInput;
	cout << NEWLINE;
	string toDelete;
	if (userInput == 0)
	{
		toDelete = "Shopping";
	}
	else if (userInput == 1)
	{
		toDelete = "Housing";
	}
	else if (userInput == 2)
	{
		toDelete = "Work";
	}
	list* goThrough = headPtr;
	while (goThrough != nullptr)
	{
		if (toDelete == goThrough->item.getType())
		{
			deleteItemId(goThrough->item.getId());
		}
		goThrough = goThrough->next;
	}
}

void ToDoList::deleteItemStatus()
{
	//Status
	int userInput;
	cout << "Enter the type you would like to delete : Done = 0, InProgress = 1, Hold = 2" << NEWLINE;
	cin >> userInput;
	cout << NEWLINE;
	string toDelete;
	if (userInput == 0)
	{
		toDelete = "Done";
	}
	else if (userInput == 1)
	{
		toDelete = "InProgress";
	}
	else if (userInput == 2)
	{
		toDelete = "Hold";
	}
	list* goThrough = headPtr;
	while (goThrough != nullptr)
	{
		if (toDelete == goThrough->item.getStatus())
		{
			deleteItemId(goThrough->item.getId());
		}
		goThrough = goThrough->next;
	}
}

void ToDoList::writeToFile()
{
	ofstream outfile;
	outfile.open("writeToFile.txt");
	if (!outfile.is_open())
	{
		cout << "Error : File can not be opened";
	}
	list* traverse = headPtr;
	while (traverse != nullptr)
	{
		outfile << traverse->item.getId() << ","
			<< traverse->item.getTitle() << ","
			<< traverse->item.getDescription() << ","
			<< traverse->item.getType() << ","
			<< traverse->item.getPriority() << ","
			<< traverse->item.getStatus() << ",";
		//CREATE DATE
		if (traverse->item.getCreateDate().month < 10)
		{
			outfile << "0";
		}
		outfile << traverse->item.getCreateDate().month;

		if (traverse->item.getCreateDate().day < 10)
		{
			outfile << "0";
		}
		outfile << traverse->item.getCreateDate().day << traverse->item.getCreateDate().year << ",";
		//DUE DATE
		if (traverse->item.getDueDate().month < 10)
		{
			outfile << "0";
		}
		outfile << traverse->item.getDueDate().month;

		if (traverse->item.getDueDate().day < 10)
		{
			outfile << "0";
		}
		outfile << traverse->item.getDueDate().day << traverse->item.getDueDate().year << ",";
		//MODIFIED DATE
		if (traverse->item.getModifiedDate().month < 10)
		{
			outfile << "0";
		}
		outfile << traverse->item.getModifiedDate().month;

		if (traverse->item.getModifiedDate().day < 10)
		{
			outfile << "0";
		}
		outfile << traverse->item.getModifiedDate().day << traverse->item.getModifiedDate().year;

		outfile << NEWLINE;
		traverse = traverse->next;
	}
	outfile.close();
}

void ToDoList::readFromFile()
{
	ifstream infile;
	infile.open("writeToFile.txt");
	if (!infile.is_open())
	{
		cout << "Error : File can not be opened";
	}
	cout << "Reading from the file" << endl;
	//Resets items to zero
	positionOfItems = 0;
	//De-allocates space in the linked list
	list* traverse = headPtr;
	list* store;
	while (traverse != nullptr)
	{
		store = traverse->next;
		delete traverse;
		traverse = store;
	}
	//headPtr = new list;
	//list* traverseHead = headPtr;
	string getId;
	string title;
	string description;
	string typeString;
	string priority;
	string statusString;
	string createDate;
	string dueDate;
	string lastModifiedDate;
	string extra;
	string line;

	while (getline(infile, line)) {
		stringstream ss(line);
		getline(ss, getId, ',');
		getline(ss, title, ',');
		getline(ss, description, ',');
		getline(ss, typeString, ',');
		getline(ss, priority, ',');
		getline(ss, statusString, ',');
		getline(ss, createDate, ',');
		getline(ss, dueDate, ',');
		getline(ss, lastModifiedDate, ',');
		
	//TYPE
		int typeInt = 0;
		if (typeString.compare("Shopping") == 0)
		{
			typeInt = 0;
		}
		else if (typeString.compare("Housing") == 0)
		{
			typeInt = 1;
		}
		else if (typeString.compare("Work") == 0)
		{
			typeInt = 2;
		}
		type filetype = static_cast<type>(typeInt);
		//PRIORITY
		int priorityPass = std::atoi(priority.c_str());
		//STATUS
		int statusInt = 0;
		if (statusString.compare("Done") == 0)
		{
			statusInt = 0;
		}
		else if (statusString.compare("InProgress") == 0)
		{
			statusInt = 1;
		}
		else if (statusString.compare("Hold") == 0)
		{
			statusInt = 2;
		}
		status filestatus = static_cast<status>(statusInt);

		//DATES
		int createDateMonth = std::atoi(createDate.substr(0, 2).c_str());
		int createDateDay = std::atoi(createDate.substr(2, 2).c_str());
		int createDateYear = std::atoi(createDate.substr(4, 4).c_str());

		int dueDateMonth = std::atoi(dueDate.substr(0, 2).c_str());
		int dueDateDay = std::atoi(dueDate.substr(2, 2).c_str());
		int dueDateYear = std::atoi(dueDate.substr(4, 4).c_str());

		int modifiedDateMonth = std::atoi(lastModifiedDate.substr(0, 2).c_str());
		int modifiedDateDay = std::atoi(lastModifiedDate.substr(2, 2).c_str());
		int modifiedDateYear = std::atoi(lastModifiedDate.substr(4, 4).c_str());

		ToDo addedItem;
		addedItem.setCreateDateFile(createDateMonth, createDateDay, createDateYear);
		addedItem.setModifiedDateFile(modifiedDateMonth, modifiedDateDay, modifiedDateYear);
		//ID
		addedItem.setId(positionOfItems);
		//Title
		addedItem.setTitle(title);
		//Description
		addedItem.setDescription(description);
		//Type
		addedItem.setType(filetype);
		//Priority
		addedItem.setPriority(priorityPass);
		//Status
		addedItem.setStatus(filestatus);;
		//Create date - no user input
		addedItem.setCreateDate();
		//Due date
		addedItem.setDueDate(dueDateMonth, dueDateDay, dueDateYear);
		//Last modified date - no user input
		addedItem.setModifiedDate();
		//Adding the item to the end of the linked list
		list* new_node = new list;
		list* traverse = headPtr;
		new_node->item = addedItem;
		new_node->next = nullptr;
		if (headPtr == nullptr)
		{
			headPtr = new_node;
		}
		else {
			while (traverse->next != nullptr)
			{
				traverse = traverse->next;
			}
			traverse->next = new_node;
		}
		positionOfItems++;
	}
	infile.close();
}

//Selection sort
void ToDoList::sortByPriority()
{
	list* i = headPtr;
	list* j = nullptr;
	list* min = nullptr;
	while (i != nullptr)
	{	
		min = i;
		j = i->next;
		while (j != nullptr)
		{
			if (j->item.getPriority() < min->item.getPriority())
			{
				min = j;
			}
			j = j->next;
		}
		ToDo temp = i->item;
		i->item = min->item;
		min->item = temp;
		i = i->next;
	}
}

//Selection sort
void ToDoList::sortByDueDate()
{
	list* i = headPtr;
	list* j = nullptr;
	list* min = nullptr;
	while (i != nullptr)
	{
		min = i;
		j = i->next;
		while (j != nullptr)
		{
			bool checkDates = false;
			if (j->item.getDueDate().month < min->item.getDueDate().month
				|| j->item.getDueDate().day < min->item.getDueDate().day
				|| j->item.getDueDate().year < min->item.getDueDate().year)
			{
				checkDates = true;
			}
			if (checkDates)
			{
				min = j;
			}
			j = j->next;
		}
		ToDo temp = i->item;
		i->item = min->item;
		min->item = temp;
		i = i->next;
	}
}

//Selection sort
void ToDoList::sortCreateDate()
{
	list* i = headPtr;
	list* j = nullptr;
	list* min = nullptr;
	while (i != nullptr)
	{
		min = i;
		j = i->next;
		while (j != nullptr)
		{
			bool checkDates = false;
			if (j->item.getCreateDate().month < min->item.getCreateDate().month
				|| j->item.getCreateDate().day < min->item.getCreateDate().day
				|| j->item.getCreateDate().year < min->item.getCreateDate().year)
			{
				checkDates = true;
			}
			if (checkDates)
			{
				min = j;
			}
			j = j->next;
		}
		ToDo temp = i->item;
		i->item = min->item;
		min->item = temp;
		i = i->next;
	}
}

