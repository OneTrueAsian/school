/*
 * SalariedEmployee.h
 *
 *  Created on: Sep 13, 2017
 *      Author: adams
 */

#ifndef SALARIEDEMPLOYEE_H_
#define SALARIEDEMPLOYEE_H_

#include "Employee.h"

class SalariedEmployee : public Employee {
public:
	SalariedEmployee();
	SalariedEmployee(const string& title, const string& name,
			  	  	  	  unsigned id, double salary);
	double getSalary() const;
	void readFrom(istream & in);
private:
	double mySalary;
};

#endif /* SALARIEDEMPLOYEE_H_ */
