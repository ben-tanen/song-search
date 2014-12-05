#ifndef __wordTrieNode_h__
#define __wordTrieNode_h__

#include "Song.h"

#define numCharacters 36
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
		int  char_to_ascii(char x);

	private:
		char          letter;
		wordTrieNode* children[numCharacters];
		bool          isWord;
		topSong       topSongs[numTopSongs];
};

#endif

