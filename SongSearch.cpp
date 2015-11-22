// Authors: Gwen Schuman & Mathew Le

#include <cstring>
#include "SongSearch.h"
#include "SearchRunner.h"
#include "mynew.h"
#define MAX_SONG 42553 

/* 
  We were not allowed to use enumerate types
*/
const unsigned short TITLE  = 0;
const unsigned short ARTIST = 1;
const unsigned short ALBUM = 2;
const unsigned short ID = 3;

void SongSearch::printSong(const char *songTitle, const char *songArtist, const char *songAlbum, const char *songID, int songCount)
{
  for (int i = 0; i < songCount; i++)
  {
    cout << songTitle[i] << "@" << songArtist[i] << "@" << songAlbum[i] << "@" << songID[i] << endl;
  } //for each song
} //printSong
  

/* 
  This function creates the song library by storing the song information into the hash tables
*/
SongSearch::SongSearch(const Song *songs, int songCount) : songArtist(6010), songAlbum(4510), songTitle(14090),
  songID(7010)
{
  unsigned int i = 0;
 
  while (i < 42553)
  {

    songIndex[i][ARTIST] = songArtist.insert(songs[i].artist, i);
    songIndex[i][ALBUM] = songAlbum.insert(songs[i].album, i);
    songIndex[i][TITLE] = songTitle.insert(songs[i].title, i);
    songIndex[i][ID] = songID.insert(songs[i].ID, i);
   
    i++;
  } //while

  
} // SongSearch()


void SongSearch::Copy(unsigned short ignore, unsigned short index, Song answer[], int *answerCount)
{
  if (ignore != TITLE)
    strcpy(answer[*answerCount].title, songTitle.array[songIndex[index][TITLE]].info);

  if (ignore != ARTIST)
    strcpy(answer[*answerCount].artist, songArtist.array[songIndex[index][ARTIST]].info);

  if (ignore != ALBUM)
    strcpy(answer[*answerCount].album, songAlbum.array[songIndex[index][ALBUM]].info);

  if (ignore != ID)
    strcpy(answer[*answerCount].ID, songID.array[songIndex[index][ID]].info);

} //copyEverythingBut


/*
  Carries out the user's commands by interpretting the text file
*/
void SongSearch::query(const Request &request, Song answer[], int *answerCount)
{
  unsigned short index = -3, hashIndex = -3;
  *answerCount = 0;

  switch(request.type)
  {
    case 0: 
    {
      for(unsigned short i = 0; i < songTitle.tableSz; i++)
      {
        if (songTitle.array[i].info != (const char*)NULL)
        {
          if (strstr(songTitle.array[i].info, request.criteria) != 0)
          {
            for(unsigned short j = 0; j < songTitle.array[i].count; j++)
            {
              strcpy(answer[*answerCount].title, songTitle.array[i].info);
              index = songTitle.array[i].songPos[j];
              Copy(TITLE, index, answer, answerCount);
              (*answerCount)++;
            } //for
          } //if matches criteria
        } //if not NULL
      } //for each title
      break;
    }; //case 0


    case 1: 
    {
      hashIndex = songTitle.find(request.criteria);
      
      for(unsigned short i = 0; i < songTitle.array[hashIndex].count; i++)
      {
        if (songTitle.array[hashIndex].info != (const char*) NULL)
        {
          strcpy(answer[*answerCount].title, songTitle.array[hashIndex].info);
          index = songTitle.array[hashIndex].songPos[i];
          Copy(TITLE, index, answer, answerCount);
          (*answerCount)++;
        } //if not NULL
      } //for each title that matches
      break; 
    }; //case 1 match title exactly


    case 2:
    {
      hashIndex = songArtist.find(request.criteria);
      
      for(unsigned short i = 0; i < songArtist.array[hashIndex].count; i++)
      {
        if (songArtist.array[hashIndex].info != (const char*) NULL)
        {
          strcpy(answer[*answerCount].artist, songArtist.array[hashIndex].info);
          index = songArtist.array[hashIndex].songPos[i];
          Copy(ARTIST, index, answer, answerCount);
          (*answerCount)++;
        }
      } //for each title

     break;
    }; //case 2 match artist exactly


    case 3:
    { 
      for(unsigned short i = 0; i < songID.tableSz; i++)
      {
        if (songID.array[i].info != (const char*) NULL)
        {
          if (strcmp(songID.array[i].info, request.criteria) >= 0 && strcmp(songID.array[i].info, request.criteria2) <= 0)
          {
            for(unsigned short k = 0; k < songID.array[i].count; k++)
            {
              strcpy(answer[*answerCount].ID, songID.array[i].info);
              index = songID.array[i].songPos[k];
              Copy(ID, index, answer, answerCount);
              (*answerCount)++;
            } //for
          } //if matches criteria
      } //if not NULL
      } //for each ID
      break;
    }; //case 3 ranged find on ID

    case 4: 
    {
      hashIndex = songAlbum.find(request.criteria);
      

      for(unsigned short i = 0; i < songAlbum.array[hashIndex].count; i++)
      {
        if (songAlbum.array[hashIndex].info != (const char*) NULL)
        {
          strcpy(answer[*answerCount].album, songAlbum.array[hashIndex].info);
          index = songAlbum.array[hashIndex].songPos[i];
          Copy(ALBUM, index, answer, answerCount);
          (*answerCount)++;
        } //if not NULL

        
      } //for each title
      break;
    }; //case 4 match album exactly

   } //switch criteria
} //query()