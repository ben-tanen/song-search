#
# Makefile for SongSearch, Assignment 6
#
CXX = clang++
FLAGS = -Wall -g3

songsearch: main.cpp songSearch.cpp songSearch.h  Song.h Song.cpp wordTrie.h wordTrie.cpp wordTrieNode.cpp wordTrieNode.h read_lyrics.h read_lyrics.cpp
	${CXX} ${FLAGS} -o songsearch songSearch.cpp main.cpp Song.cpp wordTrie.cpp wordTrieNode.cpp read_lyrics.cpp
	
clean:
	rm -rf songsearch *.dSYM core*

# For sending from local computer to Homework Server
send:
	scp *.cpp *.h ReadMe.md Makefile btanen01@homework.cs.tufts.edu:~/Desktop/comp15/hw6

provide_design:
	provide comp15 hw6_design songsearch_design.txt

provide:
	provide comp15 hw6 main.cpp songSearch.cpp songSearch.h Song.h Song.cpp wordTrie.h wordTrie.cpp wordTrieNode.cpp wordTrieNode.h read_lyrics.h read_lyrics.cpp Makefile ReadMe.md songsearch_design.txt

