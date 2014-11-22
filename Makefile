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

test: wordTrieNode.cpp wordTrieNode.h wordTrie.h wordTrie.cpp trie_test.cpp
	${CXX} ${FLAGS} -o test_file wordTrieNode.cpp wordTrie.cpp trie_test.cpp

