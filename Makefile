#
# Makefile for SongSearch, Assignment 6
#
CXX = clang++
FLAGS = -Wall -g3

songsearch: songSearch.cpp songSearch.h search_test.cpp Song.h Song.cpp wordTrie.h wordTrie.cpp wordTrieNode.cpp wordTrieNode.h read_lyrics.h read_lyrics.cpp
	${CXX} ${FLAGS} -o songSearch songSearch.cpp search_test.cpp Song.cpp wordTrie.cpp wordTrieNode.cpp read_lyrics.cpp
	
clean:
	rm -rf songSearch *.dSYM core*

send:
	scp *.cpp btanen01@homework.cs.tufts.edu:~/Desktop/comp15/hw6
	scp *.h btanen01@homework.cs.tufts.edu:~/Desktop/comp15/hw6
	scp ReadMe.md btanen01@homework.cs.tufts.edu:~/Desktop/comp15/hw6

provide_design:
	provide comp15 hw6_design songsearch_design.txt

provide:
	provide comp15 hw6 songSearch.cpp songSearch.h search_test.cpp Song.h Song.cpp wordTrie.h wordTrie.cpp wordTrieNode.cpp wordTrieNode.h read_lyrics.h read_lyrics.cpp

