#ifndef __wordTrie_h__
#define __wordTrie_h__

#include "Song.h"
#include "wordTrieNode.h"

#define numLetters 26

class wordTrie {
	public:
		wordTrie();
		~wordTrie();
		void addWord(string word, int song_index);
		bool hasWord(string word);
		int  topSongN(string word, int n);
		void sortTopSongs(string word);

	private:
		wordTrieNode root;
};

#endif

