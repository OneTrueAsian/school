/*
 * SongClass.h
 *
 *  Created on: Sep 12, 2017
 *      Author: jjf25
 */

#ifndef SONG_H_
#define SONG_H_
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <cstdlib>
using namespace std;


class Song {
public:
	void readFrom(istream&);
	Song();
	Song(const string&, const string&, unsigned);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void writeTo(ostream&)const;


private:
	string  myTitle;
	string  myArtist;
	unsigned myYear;
};

#endif /* SONG_H_ */
