/*
 * PlaylistClass.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: jjf25
 */

#include "Playlist.h"
#include <fstream>      // ifstream
#include <cassert>      // assert()
#include <vector>
#include <string>
using namespace std;


/* PlayList constructor
* @param: fileName, a string
* Precondition: fileName contains the name of a playlist file.
*/
Playlist::Playlist(const string& fileName) {

// open a stream to the playlist file
	  ifstream fin( fileName.c_str() );
	  assert( fin.is_open() );

	  // read each song and append it to mySongs
	  Song s;
	  string separator;
	  while (true) {
		  s.readFrom(fin);
		  if ( !fin ) { break; }
		  getline(fin, separator);
		  mySongs.push_back(s);
	  }

	  // close the stream
	  fin.close();

}

/* Retrieve length of the playlist
* Return: the number of songs in the playlist.
*/
unsigned Playlist::getNumSongs() const {
	return mySongs.size();
}

/* Search by artist
* @param: artist, a string.
* Return: a vector containing all the Songs in mySongs by artist.
*/
vector <Song> Playlist::searchByArtist(const string& artist)const {
  vector<Song> v;

  for (unsigned i = 0; i < mySongs.size(); i++) {
	 if ( mySongs[i].getArtist().find(artist)!= string::npos ) {
		v.push_back( mySongs[i] );
	 }
  }

  return v;
}
