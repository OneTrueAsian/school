/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
    Vec();
    virtual ~Vec();
    Vec(unsigned size);
    Vec(const Vec& original);
    Vec& operator=(const Vec& original);
    unsigned getSize() const;
    void setItem(unsigned index, const Item& it);
    Item getItem(unsigned index) const;
    void setSize(unsigned newSize);
    bool operator==(const Vec& v2);
    void writeToStream(ostream& out) const;
    void readFromStream(istream& in);
    bool operator!=(const Vec& v);
    Vec operator+(const Vec& addend);
    Vec operator-(const Vec& addend);
    double operator*(const Vec& factor);
    void readFrom(string filename);
    void writeTo(string filename) const;
    Item& operator[](unsigned index);
    const Item& operator[](unsigned index) const;
private:
    unsigned mySize;
    Item *   myArray;
    friend class VecTester;
};

#endif /*VEC_H_*/
