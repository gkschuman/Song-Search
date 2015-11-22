//BASED ON WEISS"S FILES
        #ifndef _QUADRATIC_PROBING_H_
        #define _QUADRATIC_PROBING_H_

        #include "vector.h"
        #include "mystring.h"
	#include <cstring>
	#include <iostream>

        // QuadraticProbing Hash table class
        //
        // CONSTRUCTION: an initialization for ITEM_NOT_FOUND
        //               and an approximate initial size or default of 101
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // void remove( x )       --> Remove x
        // Hashable find( x )     --> Return item that matches x
        // void makeEmpty( )      --> Remove all items
        // int hash( String str, int tableSize )
        //                        --> Static method to hash strings




	class Generic {
	public:
		unsigned short *songPos;
		unsigned short count;
		char* info;
		unsigned short length;
		Generic();
	};

	
	class QuadraticHashTable {
	public:
		unsigned short tableSz;
		unsigned short currentSz;
		Generic *array;
		QuadraticHashTable(unsigned short size = 101);
		unsigned short hash(const char *input) const;
		unsigned short insert(const char *input, unsigned short index);
		unsigned short find(const char* input) const;
	};






        #endif
