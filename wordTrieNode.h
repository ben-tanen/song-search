#ifndef __wordTrieNode_h__
#define __wordTrieNode_h__

#include "Song.h"

#define numLetters 26
#define numTopSongs 11

class wordTrieNode {
	public:
		wordTrieNode();
		wordTrieNode(char new_letter);
		~wordTrieNode();
		bool addChild(char new_letter);
		wordTrieNode* getChild(char child_letter);
		char getLetter() { return letter; }
		void setWord() { isWord = true; }
		bool checkWord() { return isWord; }
		void incrementSong(int song_index);
		int  topSongN(int n) { return topSongs[n].song_index; }
		void sortTopSongs();

	private:
		char          letter;
		wordTrieNode* children[numLetters];
		bool          isWord;
		topSong       topSongs[numTopSongs];
};

#endif

