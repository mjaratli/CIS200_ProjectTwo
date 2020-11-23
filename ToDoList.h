#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef TODOLIST_H
#define TODOLIST_H
#include "ToDo.h"
#include <iostream>
#include <string>

struct list
{
	ToDo item;
	list* next;
};

class ToDoList {
private:
	list* headPtr;
	void refreshItemId();

public:
	//Constructor
	ToDoList();
	//Copy Constructor 
	void deepCopy(list* old_linked_list, list*& new_linked_list);
	//Merge
	void merge(ToDoList& rhs);
	//Printing
	void printTestingThings();
	void printByType(string t);
	void printByPriority(int pNum);
	void printById(int idNum);
	//Adding, edditing, and deleting
	void addItem(string title, string description, type t, int priority, status s, int month, int day, int year);
	void editItemId(int id, int edit);
	void deleteItemId(int id);
	void deleteItemType();
	void deleteItemStatus();
	//File functions
	void writeToFile();
	void readFromFile();
	//SORTS
	void sortByPriority();
	void sortByDueDate();
	void sortCreateDate();
};

#endif