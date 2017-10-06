/* Vec.h provides a simple vector class named Vec.
 * Student Name: Joey Faas
 * Date:Oct 4th, 2017
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 * Continued by: Joey Faas and Oshomah Agbugui for project 04
 */

#ifndef VEC_H_
#define VEC_H_
#include <cstdlib>
#include <stdexcept>
#include <ostream>
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

template<class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2)const;
	void writeToStream(ostream& out) const;
	void readFromStream(istream& in);
	Item& operator[](unsigned index);
	const Item& operator[](unsigned) const;
	bool operator!=(const Vec& v);
	void readFrom(const string& filename);
	void readFrom(istream& in);
	void writeTo(const string& filename) const;
	void writeTo(ostream& filename) const;
	Vec operator+(const Vec& addend);
	Vec operator-(const Vec& addend);
	double operator*(const Vec& factor);

private:
	unsigned mySize;
	Item * myArray;

	friend class VecTester;

};

/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Joey Faas
 * Date: 9/27/17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size]();
	if (mySize > 0) {
		for (unsigned i = 0; i < size; i++) {
			myArray[i] = 0;
		}
	} else {
		myArray = NULL;
	}
}

template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	mySize = original.mySize;
	myArray = new Item[original.mySize]();
	if (original.mySize > 0) {
		for (unsigned i = 0; i < original.mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = NULL;
	}
}

template<class Item>
Vec<Item>::~Vec() {
	mySize = 0;
	delete[] myArray;
	myArray = NULL;
}

template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {

	if (original.myArray != myArray) {
		mySize = original.mySize;
		delete[] myArray;
		myArray = new Item[original.mySize]();

		if (original.mySize > 0) {
			for (unsigned i = 0; i < mySize; i++) {
				myArray[i] = original.myArray[i];
			}
		} else {
			myArray = NULL;
		}
	}
	return *this;
}

template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (myArray != NULL) {

		if (index >= mySize) {
			throw range_error("Vec(index) is too large!");
		} else {
			myArray[index] = it;
		}
	} else {
		throw range_error("setItem(vec can not be empty)");
	}
}

template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (myArray != NULL) {
		if (index >= mySize) {
			throw range_error("Vec(index) is too large for the vector");
		} else {
			return myArray[index];
		}
	} else {
		throw range_error("Vec cannot be empty");
	}
}

template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete[] myArray;
			myArray = NULL;
			mySize = 0;
		}

		else {

			Item* newArray = new Item[newSize]();
			if (mySize < newSize) {
				for (unsigned i = 0; i < mySize; i++) {
					newArray[i] = myArray[i];
				}
				for (unsigned i = mySize + 1; i < newSize; i++) {
					newArray[i] = 0;

				}
				mySize = newSize;

			} else {
				mySize = newSize;
				for (unsigned i = 0; i < mySize; i++) {
					newArray[i] = myArray[i];
				}
			}
			myArray = newArray;
		}
	}
}

template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const{
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}

template<class Item>
void Vec<Item>::writeToStream(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << "\n";

	}
}

template<class Item>
void Vec<Item>::readFromStream(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

//changes the item at the index
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Vec(index) is too large for the vector");
	} else if (index < 0) {
		throw range_error("Vec(index) is too small for the vector");
	}
	return myArray[index];
}

//retrieves the item at the index
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Vec(index) is too large for the vector");
	} else if (index < 0) {
		throw range_error("Vec(index) is too small for the vector");
	}

	return myArray[index];
}

template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v) {
	unsigned a = 0;
	if (mySize == v.mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] == v.myArray[i]) {
				a += 1;
			}
		}
		if (a == mySize) {
			return false;
		}
	}
	return true;
}

template<class Item>
void Vec<Item>::readFrom(const string& filename) {
	ifstream fin(filename.c_str());
	assert(fin.is_open());
	unsigned newSize;
	fin>> newSize;
	setSize(newSize);
	for (unsigned i = 0; i < mySize; i++) {
		fin >> myArray[i];
	}

	fin.close();
}

template<class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}

}

template<class Item>
void Vec<Item>::writeTo(const string& filename) const {
	ofstream fout(filename.c_str());
	assert(fout.is_open());
	fout << mySize << endl;
	for (unsigned i = 0; i < mySize; i++) {
		fout << myArray[i] << endl;
	}
	fout.close();
}

template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
//	out << mySize << endl;
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}

template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& addend) {
	if (mySize != addend.mySize) {
		throw std::invalid_argument("Vectors are not the same size!");
	}
	Vec temp = *this;
	for (unsigned i = 0; i < mySize; i++) {
		temp.setItem(i, myArray[i] + addend.getItem(i));
	}
	return temp;
}

template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& addend) {
	if (mySize != addend.mySize) {
		throw std::invalid_argument("Vectors are not the same size!");
	}
	Vec temp = *this;
	for (unsigned i = 0; i < mySize; i++) {
		temp.setItem(i, myArray[i] - addend.getItem(i));
	}
	return temp;
}

template<class Item>
double Vec<Item>::operator*(const Vec<Item>& factor) {
	if (mySize != factor.mySize) {
		throw std::invalid_argument("Vectors are not the same size!");
	}
	Vec sums(mySize);
	for (unsigned i = 0; i < mySize; i++) {
		sums.setItem(i, myArray[i] * factor.myArray[i]);
	}
	double sum = 0;
	for (unsigned i = 0; i < mySize; i++) {
		sum += sums.getItem(i);
	}
	return sum;
}

#endif /*VEC_H_*/
