/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Joey Faas, Ian Park
 * Date: 9/27/17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"
#include <stdexcept>
#include <fstream>
#include <ostream>
#include <cassert>
#include <cstdlib>
using namespace std;

/* Default constructor
 * Postcondition: mySize == 0 &&
 *                myArray == NULL
 */
Vec::Vec() {
  mySize = 0;
  myArray = NULL;
}

/* Destructor
 * Postcondition: pointer to myArray is deleted
                  myArray == NULL
 *                mySize == 0
 */
Vec::~Vec() {
  delete [] myArray;
  mySize = 0;
  myArray = NULL;
}

/* Explicit constructor
 * @param: size, an unsigned int
 * Postcondition: if size is 0, it has the same value as the default constructor
 *                if it is not 0,
 *                mySize == size(the param)
 *                myArray is a new array of the size size(the param)
 */
Vec::Vec(unsigned size) {
  if ( size == 0 ) {
    mySize = 0;
    myArray = NULL;
    return;
  }
  mySize=size;
  myArray = new double[size]();
}

/* Copy Constructor
 * @param: original, a constant reference to a Vec
 * Postcondition: a new array that has the same size and values
 *                as the one passed as a parameter is created
 *
 */
Vec::Vec(const Vec& original) {
  mySize=original.mySize;
  if ( mySize == 0 ) {
    myArray=NULL;
  } else {
    myArray = new double[mySize]();
    for (unsigned i = 0; i < mySize; i++) {
      myArray[i] = original.myArray[i];
    }
  }
}

/* Assignment Operator
 * @param: original, a constant reference to a Vec
 * Return: a Vec that has the same size and values as
 *         one passed as a parameter
 */
Vec& Vec::operator=(const Vec& original) {
  if ( &original != this ) {
    if ( original.mySize != this->mySize ) {
      if ( this->mySize > 0 ) {
        delete [] this->myArray;
        this->myArray = NULL;
      }
      if ( original.mySize > 0 ) {
        this->myArray = new double[original.mySize]();
      }
      this->mySize = original.mySize;
    }
    for (unsigned i = 0; i < original.mySize; i++) {
      this->myArray[i] = original.myArray[i];
    }
  }
  return *this;
}

/* Size Accessor
 * Return: The size of the Vec
 */
unsigned Vec::getSize() const {
  return mySize;
}

/* Sets the value of an element according to an index
 * @param: title, an unsigned int
 * @param: it, a constant reference to an Item
 * Postcondition: the value of an element of a vector is
 *                set to the value of the it parameter value
 */
void Vec::setItem(unsigned index, const Item& it) {
  if ( mySize == 0 || (mySize - 1) < index) {
    throw range_error("This is a range error");
  }
  else {
    myArray[index] = it;
  }
}

/* Get the value of an element of a vector with its index
 * @param: index, an unsigned int
 * Return: an element of an array
 */
Item Vec::getItem(unsigned index) const {
  if ( mySize == 0 || (mySize - 1) < index) {
    throw range_error("This is a range error");
  }
  else {
    return myArray[index];
  }
}

/* Setting size of array
 * @param: newSize, an unsigned int
 * Postcondition: if newSize is 0,
 *                vector is destructed
 *                if newSize is greater than the size of the vector,
 *                the elemnts of the vector are copied into the new vector and
 *                the remaining values are assigned the value 0
 *                if newSize is less than the size of the vector
 *                the copied new array just gets the values within the newSize
 */
void Vec::setSize(unsigned newSize) {
  if ( mySize != newSize ) {

    if ( newSize == 0 ) {
      delete [] myArray;
      myArray = NULL;
      mySize = 0;
    }
    else {
      Item* newArray = new double[newSize]();
      if ( mySize < newSize ) {
        for (unsigned i = 0; i < mySize; i++) {
          newArray[i] = myArray[i];
        }
        for (unsigned i = mySize; i < newSize; i++) {
          newArray[i] = 0;
        }
      }
      else {
        for (unsigned i = 0; i < newSize; i++) {
          newArray[i] = myArray[i];
        }
      }
      mySize = newSize;
      delete [] myArray;
      myArray = newArray;
      newArray = NULL;
    }

  }
}

/* Equality operator, Compares a vector to another vector to see if it's equal
 * @param: v2, a constant Vec reference
 * Return: a boolean value
 */
bool Vec::operator==(const Vec& v2) {
  if ( this->mySize == v2.mySize ) {
    for (unsigned i = 0; i < this->mySize; i++) {
      if ( this->myArray[i] != v2.myArray[i] ) {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

/* Write values in the vector to ostream
 * @param: out, an ostream
 * Postcondition: Values in ostream are equal
 *                to those from the vector
 */
void Vec::writeToStream(ostream& out) const {
  for (unsigned i = 0; i < mySize; i++) {
    out << myArray[i] << "\n";
  }
}

/* Read from istream to a vector
 * @param: in, an istream
 * Postcondition: Values from vector are equal
 *                to those from the istream
 */
void Vec::readFromStream(istream& in) {
  unsigned count = 0;
  int x;

  while (count < mySize && in >> x)
    myArray[count++] = x;
}

/* Inequality operator, check inequality of two vectors
 * @param: v2, a constant Vec reference
 * Return: a boolean value
 */
bool Vec::operator!=(const Vec& v) {
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

/* Get the sum of two vectors
 * @param: addend, a constant reference a Vec
 * Return: a Vec that contains the vector sum of the two vectors
 */
Vec Vec::operator+(const Vec& addend){
    if (mySize != addend.mySize){
        throw std::invalid_argument("Vectors are not the same size!");
    }
    Vec temp = *this;
    for (unsigned i = 0; i<mySize; i++){
        temp.setItem(i, myArray[i] + addend.getItem(i));
    }
    return temp;
}

/* Get the subtracted value of two vectors
 * @param: addend, a constant reference a Vec
 * Return: a Vec that contains the vector difference of the two vectors
 */
Vec Vec::operator-(const Vec& addend){
    if (mySize != addend.mySize){
        throw std::invalid_argument("Vectors are not the same size!");
    }
    Vec temp = *this;
    for (unsigned i = 0; i<mySize; i++){
        temp.setItem(i, myArray[i] - addend.getItem(i));
    }
    return temp;
}

/* Get dot product of two vectors
 * @param: factor, a Vec
 * Postcondition: multiplies each value
 *                of the arrays and gets the sum
 * Return: sum, a double, sum of the multiplied arrays
 */
double Vec::operator*(const Vec& factor){
    if (mySize != factor.mySize){
        throw std::invalid_argument("Vectors are not the same size!");
    }
    Vec sums(mySize);
    for (unsigned i = 0; i<mySize; i++){
        sums.setItem(i, myArray[i] * factor.myArray[i]);
    }
    double sum = 0;
    for (unsigned i=0; i<mySize; i++){
        sum += sums.getItem(i);
    }
    return sum;
}

/* Read file for vector elements
 * @param: filename, a string
 * Postcondition: gets values from a file and
 *                assigns them to the array element values
 *                and deletes original vecor after completion
 */
void Vec::readFrom(string filename){
    int numvalues;
    ifstream fin(filename.c_str());
    assert(fin.is_open());

    fin >> numvalues;

    Item *temp = new Item[numvalues];

    for (int i = 0; i < numvalues; i++){
        fin >> temp[i];
    }

    delete[] myArray;

    myArray = temp;
    mySize = numvalues;
    temp = NULL;

    fin.close();
}

/* Write elements of vector to an array
 * @param: filename, a string
 * Postcondition: write values from an vector to a file
 */
void Vec::writeTo(string filename) const{
    ofstream fout(filename.c_str());
    assert(fout.is_open());
    fout << mySize << endl;
    for (unsigned i = 0; i < mySize; i++){
        fout << myArray[i] << endl;
    }
    fout.close();
}

/* Index Operator for Write(set) (changes the item at the index)
 * @param: index, an unsigned int
 * Return: the value of an element that
 *         the index points to within the operator
 */
Item& Vec::operator[](unsigned index) {
    if (index >= mySize) {
        throw range_error("Vec(index) is too large for the vector");
    }
    // else if (index < 0) {
    //     throw range_error("Vec(index) is too small for the vector");
    // }
    return myArray[index];
}

/* Index Operator for Read(get) (retrieves the item at the index)
 * @param: index, an unsigned int
 * Return: the value of an element that
 *         the index points to within the operator
 */
const Item& Vec::operator[](unsigned index) const {
    if (index >= mySize) {
        throw range_error("Vec(index) is too large for the vector");
    }
    // else if (index < 0) {
    //     throw range_error("Vec(index) is too small for the vector");
    // }
    return myArray[index];
}
