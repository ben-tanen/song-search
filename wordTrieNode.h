//
//  wordTrieNode.h
//  Class for trieNode (used in wordTrie) to store words (lyrics of songs) 
//  Written by Ben Tanen
//

#ifndef __wordTrieNode_h__
#define __wordTrieNode_h__

#include "Song.h"

#define numCharacters 36
#define numTopSongs 11

class wordTrieNode {
	public:
		// constructors / destructor
		wordTrieNode();
		wordTrieNode(char new_letter);
		~wordTrieNode();
		
		// functions dealing with Node children
		bool addChild(char new_letter);
		wordTrieNode* getChild(char child_letter);
		
		// standard setters/getters
		char getLetter() { return letter; }
		void setWord() { isWord = true; }
		bool checkWord() { return isWord; }
		int  topSongN(int n) { return topSongs[n].song_index; }
		
		// working with topSongs array
		void incrementSong(int song_index);
		void sortTopSongs();
		int  char_to_ascii(char x);

	private:
		// particular letter for Node
		char          letter;
		
		// if node is end of word
		bool          isWord;
		
		// sub-children
		wordTrieNode* children[numCharacters];
		
		// array of top10Songs (plus temp_song)
		topSong       topSongs[numTopSongs];
};

#endif

