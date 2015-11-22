SongSearch.out : mynew.o QuadraticProbing.o SearchRunner.o SongSearch.o  
	g++ -ansi -Wall -g -o SongSearch.out mynew.o QuadraticProbing.o SearchRunner.o SongSearch.o  

mynew.o : mynew.cpp mynew.h 
	g++ -ansi -Wall -g -c mynew.cpp

QuadraticProbing.o : QuadraticProbing.cpp QuadraticProbing.h
	g++ -ansi -Wall -g -c QuadraticProbing.cpp

SearchRunner.o : SearchRunner.cpp CPUTimer.h mynew.h SearchRunner.h SongSearch.h 
	g++ -ansi -Wall -g -c SearchRunner.cpp

SongSearch.o : SongSearch.cpp SongSearch.h mynew.h SearchRunner.h QuadraticProbing.h
	g++ -ansi -Wall -g -c SongSearch.cpp

clean : 
	rm -f SongSearch.out mynew.o QuadraticProbing.o SearchRunner.o  SongSearch.o   
