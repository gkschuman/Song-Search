# SongSearch

## Introduction
SongSearch is a program that reads in information about songs from a text file, songs.txt, and then processes user requests about these songs. The user can enter requests that match certain criteria from the data of the songs. 

## Description
The program takes one parameter: the name of the file containing the search requests.

Songs have a title, artists, ID (not unique), and album name. 

User requests are stored in CreateRequest.out program with a new request on each line.

Each request starts with an int (0 - 4) that indicates which of these five to use as criteria for matching. All the requests, except for type 3, have a char string that might match to song criteria. Type 3 requests have a second string to limit the ranged find. After the string, a number indicates how many songs matched the criteria. Following the number is a list of indicies of songs that match the criteria. 

*readRequests()* uses these indicies to create answers for each search query by determining the length of the four strings of all songs that match the citeria.

## Types of Queries
Type 0 = Find all songs that have titles that contain the speciified word

Type 1 = Find all songs that have the specified title.

Type 2 = Find all songs that have the specified artist.

Type 3 = Find all songs that have an ID alphabetically between criteria and criteria 2, inclusive.

Type 4 = Find all songs that have the specified album

## *SearchRunner*

## *SongSearch*