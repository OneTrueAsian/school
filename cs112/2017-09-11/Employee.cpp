/*
 * Employee.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: adams
 */

#include "Employee.h"

Employee::Employee() {
	myName = myTitle = "";
	myID = 0;
}

Employee::Employee(const string& title, const string& name, unsigned id) {
	myTitle = title;
	myName = name;
	myID = id;
}

string Employee::getTitle() const {
	return myTitle;
}

string Employee::getName() const {
	return myName;
}

unsigned Employee::getID() const {
	return myID;
}

void Employee::readFrom(istream & in) {
	in >> myTitle >> myName >> myID;
}
