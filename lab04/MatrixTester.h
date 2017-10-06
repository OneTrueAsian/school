/* MatrixTester.h declares test-methods for class Matrix.
 * Joel C. Adams, for CS 112 at Calvin College.
 * continued by Joey Faas and Oshomah Agbugui for project 04
 * Date:  Oct 4th, 2017
 */
 
#ifndef MATRIXTESTER_H_
#define MATRIXTESTER_H_

#include "Matrix.h"

class MatrixTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testExplicitConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testSubscripts();
	void testReadSubscript(const Matrix<unsigned>& mat);
	void testTranspose();
	void testAddition();
	void testSubtraction();
	void testMultiply();
	void testReadFromStream();
	void testReadFromFile();
	void testWriteToStream();
	void testWriteToFile();
};

#endif /*MATRIXTESTER_H_*/
