#
# Makefile for SongSearch, Assignment 6
#
CXX = clang++
FLAGS = -Wall -g3

songsearch: <your .cpp and .h files go here>
	${CXX} ${FLAGS} -o songsearch <your .cpp files go here>
	
clean:
	rm -rf songsearch test_file *.dSYM 

provide_design:
	provide comp15 hw6_design songsearch_design.txt

provide:
	provide comp15 hw6 <all your files go here>

test: songSearch.cpp songSearch.h search_test.cpp Song.h Song.cpp wordTrie.h wordTrie.cpp wordTrieNode.cpp wordTrieNode.h read_lyrics.h read_lyrics.cpp
	${CXX} ${FLAGS} -o test_file songSearch.cpp search_test.cpp Song.cpp wordTrie.cpp wordTrieNode.cpp read_lyrics.cpp

