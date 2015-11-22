        #include "QuadraticProbing.h"

   //Based on Weiss's Files
	using namespace std;

	Generic::Generic(): songPos((unsigned short*) NULL), count (0), info(NULL)
	{

	}

	QuadraticHashTable::QuadraticHashTable(unsigned short size) : tableSz(size), currentSz(0)
	{
		array = new Generic[size];
	}

	unsigned short QuadraticHashTable::hash(const char *input) const
	{
		unsigned short hashVal = 0;

		for (unsigned short i = 0; input[i]; i++)
			hashVal = 37 * hashVal + input[i];

		hashVal %= tableSz;

		if(hashVal < 0)
			hashVal += tableSz;

		return hashVal;
	}

	unsigned short QuadraticHashTable::insert(const char *input, unsigned short index)
	{
		unsigned short hashVal = hash(input);
		
		while(array[hashVal].info)
		{
			if(strcmp(input, array[hashVal].info) == 0)
				break;

			hashVal++;
			if (hashVal == tableSz)
				hashVal = 0;
		}
	

		unsigned short *tmp = new unsigned short [array[hashVal].count + 1];
	
		unsigned short i = 0;

		while (i < array[hashVal].count)
		{
			tmp[i] = array[hashVal].songPos[i];
			i++;
		}

		if (array[hashVal].songPos == NULL)
		{
			array[hashVal].info = new char[strlen(input) + 1];
			strcpy(array[hashVal].info, input);
			currentSz++;
		}

		else
		  delete [] array[hashVal].songPos;

		unsigned short j = 0;
		if (j == 0)
		{
			tmp[array[hashVal].count++] = index;
			array[hashVal].songPos = tmp;
 		} //if

 		else
 		{}
		return hashVal;
	}

	unsigned short QuadraticHashTable::find(const char *input) const
	{
		unsigned short collisionNum = hash(input);
		
		while(array[collisionNum].info)
		{
			if(strcmp(array[collisionNum].info, input) == 0)
				break;
			collisionNum++;

			if(collisionNum == tableSz)
				collisionNum = 0;				
		}
	
		return collisionNum;
	}


