/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: joey faas jjf25
 * Date: Oct 4th, 2017
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Continued by Joey Faas and Oshomah Agbugui for project 04
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"
#include <cstdlib>
#include <stdexcept>
#include <ostream>
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

template<class Item>

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getColumns() const;
	unsigned getRows() const;
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>&operator[](unsigned index);
	bool operator==(const Matrix& m2) const;
	bool operator!=(const Matrix& m2);
	void readFrom(istream& in);
	void readFrom(const string& filename);
	void writeTo(ostream& out)const;
	void writeTo(const string& filename) const;
	Matrix operator+(const Matrix<Item>& addend);
	Matrix operator-(const Matrix<Item>& addend);
	Matrix getTranspose();

private:
	unsigned myRows;
	unsigned myColumns;
	Vec<Vec<Item> > myVec;
	friend class MatrixTester;

};
/* Default constructor
 * Postcondition: mySize == 0 &&
 *                myArray == 0
 */
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

/*Explicit Constructor
 * @param: rows & columns are an unsigned int
 * precondition:myRows = rows
 * 				myColumns = columns
 * 				myVec size = Rows' Size
 */
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

/*Accessor: Columns
 *Return: Colunms
 */
template<class Item>
unsigned Matrix<Item>::getColumns() const {
	return myColumns;

}
/* Accessor: Rows
 * Return:Rows
 */
template<class Item>
unsigned Matrix<Item>::getRows() const {
	return myRows;
}

/* Index Operator for Read(get) (retrieves the item at the index)
 * @param: index, an unsigned int
 * Return: the value of an element that
 *         the index points to within the operator
 */
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const {
	if (index >= myRows) {
		throw range_error("Vec(index) is too large for the vector");
	} else if (index < 0) {
		throw range_error("Vec(index) is too small for the vector");
	}

	return myVec[index];
}

/* Index Operator for Write(set) (changes the item at the index)
 * @param: index, an unsigned int
 * Return: the value of an element that
 *         the index points to within the operator
 */
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index) {
	if (index >= myRows) {

		throw range_error("Vec(index) is too large for the vector");
	} else if (index < 0) {
		throw range_error("Vec(index) is too small for the vector");
	}
	return myVec[index];
}

/* Equality operator, Compares a Matrix to another Matrix to see if it's equal
 * @param: m2, a constant Matrix reference
 * Return: a boolean value
 */
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns()) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

/* Inequality operator, check inequality of two Matrices
 * @param: m2, a constant Matrix reference
 * Return: a boolean value
 */
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& m2) {
	for (unsigned i = 0; i < myRows; i++) {
		if (myVec[i] != m2.myVec[i]) {
			return true;
		}
	}
	return myRows != m2.myRows;
}

/* Read from istream to a Matrix
 * @param: in, an istream
 * Postcondition: Values from Matrix are equal
 *                to those from the istream
 */
template<class Item>
void Matrix<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			in >> myVec[i][j];
		}
	}
}

/* Read file for Matrix elements
 * @param: filename, a string
 * Postcondition: gets values from a file and
 *                assigns them to a Matrix
 */
template<class Item>
void Matrix<Item>::readFrom(const string& filename) {
	ifstream fin(filename.c_str());
	assert(fin.is_open());
	fin >> myRows;
	fin >> myColumns;
	myVec.setSize(myRows);
	for (unsigned i = 0; i < myRows; i++) {
		myVec[i].setSize(myColumns);
		for (unsigned j = 0; j < myColumns; j++) {
			fin >> myVec[i][j];
		}

	}
	fin.close();
}

/* Write values in the Matrix to ostream
 * @param: out, an ostream
 * Postcondition: Values in ostream are equal
 *                to those from the Matrix
 */
template<class Item>
void Matrix<Item>::writeTo(ostream& out)const {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			out << myVec[i][j] <<"\t";
		}
		out<<endl;
	}
}

/* Write elements of a Matrix to an Vector
 * @param: filename, a string
 * Postcondition: write values from a Matrix to a file
 */
template<class Item>
void Matrix<Item>::writeTo(const string& filename) const {
	ofstream fout(filename.c_str());
	assert(fout.is_open());
	fout << myRows << " "<< myColumns << endl;
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			fout << myVec[i][j] << "\t";
		}
		fout<<endl;
	}
}

/* Get the sum of two Matrices
 * @param: addend, a constant reference a Matrix
 * Return: a Matrix that contains the Matrix sum of the two Matrices
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& addend) {
	if (myRows != addend.getRows() || myColumns != addend.getColumns()) {
		throw std::invalid_argument("Matrcies are not the same Size");
	} else {
		Matrix<Item> temp = *this;
		for (unsigned i = 0; i < myRows; i++) {
			temp[i] = (myVec[i] + addend.myVec[i]);
		}
		return temp;
	}

}

/* Get the difference of two Matrices
 * @param: addend, a constant reference a Matrix
 * Return: a Matrix that contains the Matrix differences of the two Matrices
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator-(const Matrix<Item>& addend) {
	if (myRows != addend.getRows() || myColumns != addend.getColumns()) {
		throw std::invalid_argument("Matricies are not the same Size");
	} else {
		Matrix<Item> temp = *this;
		for (unsigned i = 0; i < myRows; i++) {
			temp[i] = (myVec[i] - addend.myVec[i]);
		}
		return temp;
	}

}

/* Switches the values of the Matrices with each other.
 * Return: Two Matrices with values from each other.
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() {
	Matrix TransposeMat(myColumns, myRows);
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			TransposeMat.myVec[j][i] = myVec[i][j];
		}
	}
	return TransposeMat;
}

#endif
