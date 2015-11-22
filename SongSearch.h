#ifndef SONGSEARCH_H
#define	SONGSEARCH_H

#include <cstring>
#include "SearchRunner.h"
#include "QuadraticProbing.h"

/*
  Each song's information is stored into hashtables, and the indivdual song's artist, album, title, and ID are 
  linked together by a unique song Index number.
*/


class SongSearch //Essentially the container for everything
{
  
  unsigned short songIndex[42553][4];
  QuadraticHashTable songArtist;
  QuadraticHashTable songAlbum;
  QuadraticHashTable songTitle;
  QuadraticHashTable songID;
public:
  SongSearch(const Song *songs, int songCount);
  void query(const Request &request, Song answer[], int *answerCount);
  void printSong(const char * songTitle, const char * songArtist, const char *songAlbum, const char *songID, int songCount);
  void Copy(unsigned short ignore, unsigned short index, Song answer[], int *answerCount);

}; // class SongSearch 

#endif