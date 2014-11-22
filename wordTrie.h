#ifndef __wordTrie_h__
#define __wordTrie_h__

#include "wordTrieNode.h"
#include "Song.h"

#define numLetters 26

class wordTrie {
	public:
		wordTrie();
		~wordTrie();
		void addWord(string word);
		bool hasWord(string word);

		// return the top songs for a particular word
		// topSong hasWord(string word);


	private:
		wordTrieNode root;
};

#endif

