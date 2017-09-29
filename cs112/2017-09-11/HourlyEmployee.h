/*
 * HourlyEmployee.h
 *
 *  Created on: Sep 13, 2017
 *      Author: adams
 */

#ifndef HOURLYEMPLOYEE_H_
#define HOURLYEMPLOYEE_H_

#include "Employee.h"

class HourlyEmployee: public Employee {
public:
	HourlyEmployee();
	HourlyEmployee(const string& title, const string& name, unsigned id,
						double hours, double wage);
	double getHours() const                        { return myHours; }
	double getWage() const                         { return myWage; }
	void readFrom(istream & in);
private:
	double myHours;
	double myWage;
};

#endif /* HOURLYEMPLOYEE_H_ */
