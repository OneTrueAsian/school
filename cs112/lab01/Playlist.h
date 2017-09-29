/* created for lab01 for creating a song and playlist class
 * PlayList.h declares class PlayList.
* Student Name: Joey Faas jjf25
* Date: 9/12/17
* Begun by: Joel Adams, for CS 112 at Calvin College.
*/

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector>   // STL vector
#include <string>
using namespace std;



class Playlist {

public:
	vector<Song> searchByArtist(const string&)const;
	void runtTests();
	void testConstructors();
	Playlist(const string& filename);
	unsigned getNumSongs() const;
private:
      vector<Song> mySongs;
};



#endif /* PLAYLIST_H_ */
