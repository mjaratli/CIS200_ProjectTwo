#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef TODO_H
#define TODO_H
#include <iostream>
#include <string>
using std::string;


enum type { Shopping, Housing, Work };
enum status { Done, InProgress, Hold };
struct Date {
	int month;
	int day;
	int year;
};

class ToDo
{
private:
	int m_id;
	string m_title;
	string m_description;
	int m_priority;
	//Creating the enums
	type m_type;
	status m_status;
	Date m_create_date;
	Date m_due_date;
	Date m_modified_date;


public:

	//Constructors
	//Default 
	ToDo();
	//Title, Description, Type
	ToDo(string title, string description, type t);
	//Title, Type, Priority
	ToDo(string title, type t, int priority);
	//Title, Type, Priority, Due date
	ToDo(string title, type t, int priority, int month, int day, int year);

	//Equals operator
	void operator=(const ToDo& rhs);


	//Set and Get functions
	void setId(int id);
	int getId();

	void setTitle(string title);
	string getTitle();

	void setDescription(string description);
	string getDescription();

	void setType(type t);
	string getType();
	type getTypeType();

	void setPriority(int priority);
	int getPriority();

	void setStatus(status s);
	string getStatus();
	status getStatusStatus();

	void setCreateDate();
	Date getCreateDate();
	void setCreateDateFile(int month, int day, int year);

	void setDueDate(int month, int day, int year);
	Date getDueDate();

	void setModifiedDate();
	Date getModifiedDate();
	void setModifiedDateFile(int month, int day, int year);

};

#endif