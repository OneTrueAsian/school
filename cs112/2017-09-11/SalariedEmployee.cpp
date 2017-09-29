/*
 * SalariedEmployee.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: adams
 */

#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee()
: Employee()
{
	mySalary = 0.0;
}

SalariedEmployee::SalariedEmployee(const string& title, const string& name,
			  	  	  	  unsigned id, double salary)
 : Employee(title, name, id)
{
//	super(title, name, id);  // Java
//	myTitle = title;
//	myName = name;
//	myID = id;
	mySalary = salary;
}

double SalariedEmployee::getSalary() const {
	return mySalary;
}

void SalariedEmployee::readFrom(istream & in) {
//	in >> myTitle >> myName >> myID;
	Employee::readFrom(in);
	in >> mySalary;
}
