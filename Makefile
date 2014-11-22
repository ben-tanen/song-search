#
# Makefile for SongSearch, Assignment 6
#
CXX = clang++
FLAGS = -Wall -g3

songsearch: <your .cpp and .h files go here>
	${CXX} ${FLAGS} -o songsearch <your .cpp files go here>
	
clean:
	rm -f songsearch

provide_design:
	provide comp15 hw6_design songsearch_design.txt

provide:
	provide comp15 hw6 <all your files go here>

test: Song.cpp Song.h song_test.cpp
	${CXX} ${FLAGS} -o test_file Song.cpp song_test.cpp

