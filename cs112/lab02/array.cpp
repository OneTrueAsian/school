/* array.cpp defines "C style" array operations
 * Name:joey faas
 * Date:9/19/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"
using namespace std;



void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
 
void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

double average(double *a, unsigned size) {
	double sum = 0;
	double avg = 0;
	for (unsigned i = 0; i < size; i++){ //  loops through the array
		sum += *a; // the current location of a* + sum
		a++;
	}
	avg = sum/size; // get average from dividing the sum and the size
	return avg;
}
