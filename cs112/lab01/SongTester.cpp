/*created for lab01 for creating a song and playlist class
* SongTester.cpp
*
* Created on: Sep 12, 2017
* Author: jjf25
* SongTester.h declares a test-class for class Song.
*
* Student Name: Joey Faas jjf25
* Date: 9/12/17
* Begun by: Joel Adams, for CS 112 at Calvin College.
*/

#include "SongTester.h"
#include "Song.h"
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;
#include <cassert>
#include "Song.h"


void SongTester::runTests() {
	cout << "Testing class song..."<< endl;
	testConstructors();
	testReadFrom();
	testWriteTo();
	cout << "All test passed!" << endl;


}

void SongTester::testConstructors() {
	cout << "- constructors ... " << flush;
	// default constructor
	Song s;
	assert( s.getTitle() == "" );
	assert( s.getArtist() == "" );
	assert( s.getYear() == 0 );
	cout << " 0 " << flush;
	cout << " Passed!" << endl;
	// explicit constructor
	Song s1("Badge", "Cream", 1969);
	assert( s1.getTitle() == "Badge" );
	assert( s1.getArtist() == "Cream" );
	assert( s1.getYear() == 1969 );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
	}

void SongTester::testReadFrom() {
      cout << "- readFrom()... " << flush;
      ifstream fin("testSongs.txt");
      assert( fin.is_open() );
      Song s;

      // read first song in test playlist
      s.readFrom(fin);
      assert( s.getTitle() == "Call Me Maybe" );
      assert( s.getArtist() == "Carly Rae Jepsen" );
      assert( s.getYear() == 2012 );
      cout << " 0 " << flush;

      // read second song in test playlist
      string separator;
      getline(fin, separator);
      s.readFrom(fin);
      assert( s.getTitle() == "Let It Be" );
      assert( s.getArtist() == "The Beatles" );
      assert( s.getYear() == 1967 );
      cout << " 1 " << flush;

      // read third song in test playlist
      getline(fin, separator);
      s.readFrom(fin);
      assert( s.getTitle() == "Let It Be" );
      assert( s.getArtist() == "Joan Baez" );
      assert( s.getYear() == 1971 );
      cout << " 2 " << flush;

      fin.close();
      cout << "Passed!" << endl;
   }

void SongTester::testWriteTo() {
      cout << "- writeTo()... " << flush;

      // declare three songs
      Song s1("Badge", "Cream", 1969);
      Song s2("Godzilla", "Blue Oyster Cult", 1977);
      Song s3("Behind Blue Eyes", "The Who", 1971);

      // write the three songs to an output file
      ofstream fout("testSongOutput.txt");
      assert( fout.is_open() );
      s1.writeTo(fout);
      s2.writeTo(fout);
      s3.writeTo(fout);
      fout.close();

      // use readFrom() to see if writeTo() worked
      ifstream fin("testSongOutput.txt");
      assert( fin.is_open() );
      Song s4, s5, s6;

      // read and check the first song
      s4.readFrom(fin);
      assert( s4.getTitle() == "Badge" );
      assert( s4.getArtist() == "Cream" );
      assert( s4.getYear() == 1969 );
      cout << " 0 " << flush;

      // read and check the second song
      s5.readFrom(fin);
      assert( s5.getTitle() == "Godzilla" );
      assert( s5.getArtist() == "Blue Oyster Cult" );
      assert( s5.getYear() == 1977 );
      cout << " 1 " << flush;

      // read and check the third song
      s6.readFrom(fin);
      assert( s6.getTitle() == "Behind Blue Eyes" );
      assert( s6.getArtist() == "The Who" );
      assert( s6.getYear() == 1971 );
      cout << " 2 " << flush;

      fin.close();
      cout << " Passed!" << endl;
}





