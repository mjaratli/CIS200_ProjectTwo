#define _CRT_SECURE_NO_WARNINGS
#include "ToDo.h"
#include <iostream>
#include <ctime>

int idNumber = 0;

//Constructors 
//Default 
ToDo::ToDo()
{
	m_id = idNumber++;
	m_title = "None";
	m_description = "None";
	type defaultType = Shopping;
	m_type = defaultType;
	m_priority = 0;
	status defaultStatus = Done;
	m_status = defaultStatus;
	//Time Created
	time_t currentime = time(0);
	tm* ltm = localtime(&currentime);
	int yearVar = 1900 + ltm->tm_year;
	int monthVar = 1 + ltm->tm_mon;
	int dayVar = ltm->tm_mday;
	m_create_date.month = monthVar;
	m_create_date.day = dayVar;
	m_create_date.year = yearVar;
	//Default due date
	m_due_date.month = 0;
	m_due_date.day = 0;
	m_due_date.year = 0;
	//Default last modified date
	m_modified_date.month = 0;
	m_modified_date.day = 0;
	m_modified_date.year = 0;

}
//Title, Description, Type
ToDo::ToDo(string title, string description, type t)
{
	m_id = idNumber++;
	m_title = title;
	m_description = description;
	m_type = t;
	//Time Created
	time_t currentime = time(0);
	tm* ltm = localtime(&currentime);
	int yearVar = 1900 + ltm->tm_year;
	int monthVar = 1 + ltm->tm_mon;
	int dayVar = ltm->tm_mday;
	m_create_date.month = monthVar;
	m_create_date.day = dayVar;
	m_create_date.year = yearVar;
}
//Title, Type, Priority
ToDo::ToDo(string title, type t, int priority)
{
	m_id = idNumber++;
	m_title = title;
	m_type = t;
	m_priority = priority;
	//Time Created
	time_t currentime = time(0);
	tm* ltm = localtime(&currentime);
	int yearVar = 1900 + ltm->tm_year;
	int monthVar = 1 + ltm->tm_mon;
	int dayVar = ltm->tm_mday;
	m_create_date.month = monthVar;
	m_create_date.day = dayVar;
	m_create_date.year = yearVar;
}
//Title, Type, Priority, Due date
ToDo::ToDo(string title, type t, int priority, int month, int day, int year)
{
	m_id = idNumber++;
	m_title = title;
	m_type = t;
	m_priority = priority;
	m_due_date.month = month;
	m_due_date.day = day;
	m_due_date.year = year;
	//Time Created
	time_t currentime = time(0);
	tm* ltm = localtime(&currentime);
	int yearVar = 1900 + ltm->tm_year;
	int monthVar = 1 + ltm->tm_mon;
	int dayVar = ltm->tm_mday;
	m_create_date.month = monthVar;
	m_create_date.day = dayVar;
	m_create_date.year = yearVar;
}

//Set and get functions 
void ToDo::setId(int id)
{
	m_id = id;
}
int ToDo::getId()
{
	return m_id;
}

void ToDo::setTitle(string title)
{
	m_title = title;
}
string ToDo::getTitle()
{
	return m_title;
}

void ToDo::setDescription(string description)
{
	m_description = description;
}
string ToDo::getDescription()
{
	return m_description;
}

void ToDo::setType(type t)
{
	switch (t)
	{
	case Shopping:
		m_type = Shopping;
		break;
	case Housing:
		m_type = Housing;
		break;
	case Work:
		m_type = Work;
		break;
	}
}
string ToDo::getType()
{
	switch (m_type)
	{
	case Shopping:
		return "Shopping";
		break;
	case Housing:
		return "Housing";
		break;
	case Work:
		return "Work";
		break;
		return "Invalid";
	}
}

type ToDo::getTypeType()
{
	return m_type;
}

void ToDo::setPriority(int priority)
{
	m_priority = priority;
}
int ToDo::getPriority()
{
	return m_priority;
}

void ToDo::setStatus(status s)
{
	switch (s)
	{
	case Done:
		m_status = Done;
		break;
	case InProgress:
		m_status = InProgress;
		break;
	case Hold:
		m_status = Hold;
		break;
	}
}

status ToDo::getStatusStatus()
{
	return m_status;
}

string ToDo::getStatus()
{
	switch (m_status)
	{
	case Done:
		return "Done";
		break;
	case InProgress:
		return "InProgress";
		break;
	case Hold:
		return "Hold";
		break;
		return "Invalid";
	}
}

void ToDo::setCreateDate()
{
	time_t currentime = time(0);
	tm* ltm = localtime(&currentime);
	int yearVar = 1900 + ltm->tm_year;
	int monthVar = 1 + ltm->tm_mon;
	int dayVar = ltm->tm_mday;
	m_create_date.month = monthVar;
	m_create_date.day = dayVar;
	m_create_date.year = yearVar;
}
Date ToDo::getCreateDate()
{
	return m_create_date;
}

void ToDo::setCreateDateFile(int month, int day, int year)
{
	m_create_date.month = month;
	m_create_date.day = day;
	m_create_date.year = year;
}

void ToDo::setDueDate(int month, int day, int year)
{
	m_due_date.month = month;
	m_due_date.day = day;
	m_due_date.year = year;
}
Date ToDo::getDueDate()
{
	return m_due_date;
}

void ToDo::setModifiedDate()
{
	time_t currentime = time(0);
	tm* ltm = localtime(&currentime);
	int yearVar = 1900 + ltm->tm_year;
	int monthVar = 1 + ltm->tm_mon;
	int dayVar = ltm->tm_mday;
	m_modified_date.month = monthVar;
	m_modified_date.day = dayVar;
	m_modified_date.year = yearVar;
}
Date ToDo::getModifiedDate()
{
	return m_modified_date;
}

void ToDo::setModifiedDateFile(int month, int day, int year)
{
	m_modified_date.month = month;
	m_modified_date.day = day;
	m_modified_date.year = year;
}

void ToDo::operator=(const ToDo & rhs) 
{
	this->setId(rhs.m_id);
	this->setTitle(rhs.m_title);
	this->setDescription(rhs.m_description);
	this->setPriority(rhs.m_priority);
	this->setType(rhs.m_type);
	this->setStatus(rhs.m_status);
	this->setCreateDateFile(rhs.m_create_date.month, rhs.m_create_date.day, rhs.m_create_date.year);
	this->setDueDate(rhs.m_due_date.month, rhs.m_create_date.day, rhs.m_create_date.year);
	this->setModifiedDateFile(rhs.m_modified_date.month, rhs.m_modified_date.day, rhs.m_modified_date.year);

}