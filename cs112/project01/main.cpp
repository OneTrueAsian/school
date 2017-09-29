/*
 * created for lab01 for creating a song and playlist class
* main.cpp tests the classes in our project. *
*  Created on: Sep 12, 2017
*      Author: jjf25
*    SongTester.h declares a test-class for class Song.
*
* Student Name: Joey Faas jjf25
* Date: 9/12/17
* Begun by: Joel Adams, for CS 112 at Calvin College.
*/


#include <iostream>
#include <string>
#include "SongTester.h"
#include "PlaylistTester.h"
using namespace std;


int main() {
	SongTester sTester;
	sTester.runTests();
	PlaylistTester plTester;
	plTester.runTests();
}
