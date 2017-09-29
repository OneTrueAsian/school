/*
 * HourlyEmployee.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: adams
 */

#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee()
 : Employee()
{
	myHours = myWage = 0.0;
}

HourlyEmployee::HourlyEmployee(const string& title, const string& name, unsigned id,
						double hours, double wage)
: Employee(title, name, id)
{
	myHours = hours;
	myWage = wage;
}

void HourlyEmployee::readFrom(istream & in) {
	Employee::readFrom(in);
	in >> myHours >> myWage;
}
