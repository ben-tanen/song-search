#include "wordTrie.h"
#include "wordTrieNode.h"

using namespace std;

wordTrie::wordTrie() {

}

wordTrie::~wordTrie() {

}

void wordTrie::addWord(string word) {
	root.addChild(word[0]);
	wordTrieNode *temp = root.getChild(word[0]);
	for (int i=1; i<word.length(); i++) {
		temp->addChild(word[i]);
		temp = temp->getChild(word[i]);
	}

	temp->setWord();
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




