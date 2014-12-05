//
//  wordTrie.cpp
//  Class for trie to store words (lyrics of songs) 
//  Written by Ben Tanen
//

#include "wordTrie.h"

using namespace std;

// constructor (nothing necessary due to class variables)
wordTrie::wordTrie() {

}

// destructor (nothing necessary due to class variables)
wordTrie::~wordTrie() {

}

// add word to trie by incrementing  frequency for particular song (song_index)
void wordTrie::addWord(string word, int song_index) {
	// add child for first letter (does nothing if child exists already)
	root.addChild(word[0]);
	
	// traverse trie for end of word
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp->addChild(word[i]);
		temp = temp->getChild(word[i]);
	}

	// set to word (if necessary) and increment frequency of song_index
	temp->setWord();
	temp->incrementSong(song_index);

	return;
}

// checks if the word exists in the trie already
bool wordTrie::hasWord(string word) {
	// check if first letter exists in trie
	if (root.getChild(word[0]) == NULL) {
		return false;
	}
	
	// traverse trie to find word
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp = temp->getChild(word[i]);

		// letter of word has yet to be included, return false
		if (temp == NULL) {
			return false;
		}
	}

	// check if last letter is end of word already (word exists)
	return temp->checkWord();
}

// sort the top10 songs for a particular word
void wordTrie::sortTopSongs(string word) {
	// traverse trie to find word
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp = temp->getChild(word[i]);
		// if any letter in word doesn't exist, return
		if (temp == NULL) {
			return;
		}
	}

	// sort topSongs within Node
	temp->sortTopSongs();
}

// returns the index of the n-th top song for a particular word
int wordTrie::topSongN(string word, int n) {
	// traverse trie to find word
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp = temp->getChild(word[i]);
		// if any letter in word doesn't exist, return -1 (fail)
		if (temp == NULL) {
			return -1;
		}
	}

	// call Node function (of same type)
	return temp->topSongN(n);
}




