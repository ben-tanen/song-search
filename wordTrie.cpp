#include "wordTrie.h"

using namespace std;

wordTrie::wordTrie() {

}

wordTrie::~wordTrie() {

}

void wordTrie::addWord(string word, int song_index) {
	root.addChild(word[0]);
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp->addChild(word[i]);
		temp = temp->getChild(word[i]);
	}

	temp->setWord();
	temp->incrementSong(song_index);


	return;
}

bool wordTrie::hasWord(string word) {
	if (root.getChild(word[0]) == NULL) {
		return false;
	}
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp = temp->getChild(word[i]);
		if (temp == NULL) {
			return false;
		}
	}

	return temp->checkWord();
}

void wordTrie::sortTopSongs(string word) {
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp = temp->getChild(word[i]);
		if (temp == NULL) {
			return;
		}
	}

	temp->sortTopSongs();
}

int wordTrie::topSongN(string word, int n) {
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp = temp->getChild(word[i]);
		if (temp == NULL) {
			return -1;
		}
	}

	return temp->topSongN(n);
}




