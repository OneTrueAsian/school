/*
 * EmployeeTester.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: adams
 */

#include "EmployeeTester.h"
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void EmployeeTester::runTests() {
	cout << "Testing class Employee..." << endl;
	testConstructors();
	testRead();
	cout << "All tests passed!" << endl;
}

void EmployeeTester::testRead() {
	cout << "- read()... " << flush;
	SalariedEmployee salEmp0;
	ifstream fin("payroll.txt");
	assert( fin.is_open() );
	char empType;
	fin >> empType;  // S
	salEmp0.readFrom(fin);
	assert( salEmp0.getTitle() == "CEO" );
	assert( salEmp0.getName() == "Anne" );
	assert( salEmp0.getID() == 1 );
	assert( salEmp0.getSalary() == 120000 );
	cout << " 0 " << flush;
	fin >> empType;  // S
	SalariedEmployee salEmp1;
	salEmp1.readFrom(fin);
	assert( salEmp1.getTitle() == "CIO" );
	assert( salEmp1.getName() == "Bob" );
	assert( salEmp1.getID() == 2 );
	assert( salEmp1.getSalary() == 100000 );
	cout << " 1 " << flush;
	HourlyEmployee hEmp0;
	fin >> empType;  // H
	hEmp0.readFrom(fin);
	assert( hEmp0.getTitle() == "Janitor" );
	assert( hEmp0.getName() == "Chris" );
	assert( hEmp0.getID() == 3);
	assert( hEmp0.getHours() == 40 );
	assert( hEmp0.getWage() == 20.00 );
	cout << " 2 " << flush;
	fin >> empType;  // H
	HourlyEmployee hEmp1;
	hEmp1.readFrom(fin);
	assert( hEmp1.getTitle() == "Contractor" );
	assert( hEmp1.getName() == "Dana" );
	assert( hEmp1.getID() == 4);
	assert( hEmp1.getHours() == 45 );
	assert( hEmp1.getWage() == 20.00 );
	cout << " 3 " << flush;
	cout << " Passed!" << endl;
}

void EmployeeTester::testConstructors() {
	cout << "- constructors... " << flush;
	Employee emp;
	assert( emp.getTitle() == "" );
	assert( emp.getName() == "" );
	assert( emp.getID() == 0 );
	cout << " 0 " << flush;
	Employee emp1("CEO", "Anne", 1);
	assert( emp1.getTitle() == "CEO" );
	assert( emp1.getName() == "Anne" );
	assert( emp1.getID() == 1 );
	cout << " 1 " << flush;
	SalariedEmployee salEmp0;
	assert( salEmp0.getTitle() == "" );
	assert( salEmp0.getName() == "" );
	assert( salEmp0.getID() == 0 );
	assert( salEmp0.getSalary() == 0.0 );
	cout << " 2 " << flush;
	SalariedEmployee salEmp1("CIO", "Betty", 2, 90000.00);
	assert( salEmp1.getTitle() == "CIO" );
	assert( salEmp1.getName() == "Betty" );
	assert( salEmp1.getID() == 2 );
	assert( salEmp1.getSalary() == 90000.00 );
	cout << " 3 " << flush;
	HourlyEmployee hourEmp0;
	assert( hourEmp0.getTitle() == "" );
	assert( hourEmp0.getName() == "" );
	assert( hourEmp0.getID() == 0 );
	assert( hourEmp0.getHours() == 0.0 );
	assert( hourEmp0.getWage() == 0.0 );
	cout << " 4 " << flush;
	HourlyEmployee hourEmp1("Janitor", "Chris", 3, 40.00, 20.00 );
	assert( hourEmp1.getTitle() == "Janitor" );
	assert( hourEmp1.getName() == "Chris" );
	assert( hourEmp1.getID() == 3 );
	assert( hourEmp1.getHours() == 40.0 );
	assert( hourEmp1.getWage() == 20.0 );
	cout << " 5 " << flush;

	cout << " Passed!" << endl;
}

