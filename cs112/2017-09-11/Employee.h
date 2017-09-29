/*
 * Employee.h
 *
 *  Created on: Sep 11, 2017
 *      Author: adams
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
	Employee();
	Employee(const string& title, const string& name, unsigned id);
	string getTitle() const;
	string getName() const;
	unsigned getID() const;
	void readFrom(istream & in);
private:
	string myTitle;
	string myName;
	unsigned myID;
};

#endif /* EMPLOYEE_H_ */
