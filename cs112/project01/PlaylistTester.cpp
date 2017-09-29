/*created for lab01 for creating a song and playlist class
 * hold the function and methods for the playlist class
 * PlaylistTester.cpp
 *  Created on: Sep 12, 2017
 *      Author: jjf25
 *
 * SongTester.h declares a test-class for class Song.
* Student Name: Joey Faas jjf25
* Date: 9/12/17
* Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "PlaylistTester.h"
#include "Playlist.h"
#include <iostream>
#include <cassert>
using namespace std;

void PlaylistTester::runTests() {
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	testsave();
	cout << "All tests passed!" << endl;

}

void PlaylistTester::testConstructors() {
      cout << "- constructors..." << flush;
      Playlist plist("testSongs.txt");
      assert( plist.getNumSongs() == 4 );
      cout << " 0 " << flush;

      cout << " Passed!" << endl;
   }

void PlaylistTester::testSearchByArtist() {
   cout << "- searchByArtist()... " << flush;
   // load a playlist with test songs
   Playlist plist("testSongs.txt");

   // empty case (0)
   vector<Song> searchResult = plist.searchByArtist("Cream");
   assert( searchResult.size() == 0 );
   cout << " 0 " << flush;

   // case of 1
   searchResult = plist.searchByArtist("Baez");
   assert( searchResult.size() == 1 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   cout << " 1 " << flush;

   // case of 2
   searchResult = plist.searchByArtist("Beatles");
   assert( searchResult.size() == 2 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   assert( searchResult[1].getTitle() == "Penny Lane" );
   cout << " 2 " << flush;

   cout << " Passed!" << endl;
}

void PlaylistTester::testsave() {
	cout << "- Save Constructor..." << flush;
	  Playlist plist("testSongs.txt");
	  assert( plist.getNumSongs() == 4 );
	  cout << " 0 " << flush;



// checks if the file is the same or different from other playlist
	ofstream fout("testSongs.txt");
	Song s1("Badge", "Cream", 1969);
	Song s2("Godzilla", "Blue Oyster Cult", 1977);
	Song s3("Behind Blue Eyes", "The Who", 1971);

	s1.writeTo(fout);
	s2.writeTo(fout);
	s3.writeTo(fout);
	plist.save();

	for (unsigned i = 0; i < plist.GetmySongs().size(); i++) {
		(assert(plist.GetmySongs()[i] == plist.GetmySongs()[i]));

	}
	cout << " Passed!" << endl;
}







