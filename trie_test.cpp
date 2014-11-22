#include <iostream>
#include "wordTrieNode.h"
#include "wordTrie.h"

using namespace std;

int main(int argc, char const *argv[])
{
	wordTrie trie;

	trie.addWord("hey");
	trie.addWord("dog");
	trie.addWord("hey");
	if (trie.hasWord("do")) { 
		cout << "yes" << endl; 
	} else {
		cout << "no" << endl;
	}

	return 0;
}