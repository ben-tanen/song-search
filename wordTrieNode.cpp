#include "wordTrieNode.h"
#include "Song.h"

using namespace std;

wordTrieNode::wordTrieNode() {
	for (int i=0; i<numLetters; i++) {
		children[i] = NULL;
	}
}

wordTrieNode::wordTrieNode(char new_letter) {
	letter = new_letter;

	for (int i=0; i<numLetters; i++) {
		children[i] = NULL;
	}
}

wordTrieNode::~wordTrieNode() {
	for (int i=0; i<numLetters; i++) {
		if (children[i] != NULL) {
			delete children[i];
		}
	}
}

bool wordTrieNode::addChild(char new_letter) {
	if (children[int(new_letter) - 97] == NULL) {
		wordTrieNode* new_node = new wordTrieNode(new_letter);
		children[int(new_letter) - 97] = new_node;
		return true;
	} else {
		return false;
	}
}

wordTrieNode* wordTrieNode::getChild(char child_letter) {
	return children[int(child_letter) - 97];
}




