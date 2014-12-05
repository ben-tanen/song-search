//
//  wordTrieNode.cpp
//  Class for trieNode (used in wordTrie) to store words (lyrics of songs) 
//  Written by Ben Tanen
//

#include "wordTrieNode.h"

using namespace std;

// constructor
wordTrieNode::wordTrieNode() {
	// initialize *children array
	for (int i=0; i<numCharacters; i++) {
		children[i] = NULL;
	}

	// initialize topSongs array
	for (int i=0; i<numTopSongs; i++) {
		topSong new_song;
		new_song.song_index = -1;
		new_song.freq = 0;
		topSongs[i] = new_song;
	}
}

// constructor (for particular new letter)
wordTrieNode::wordTrieNode(char new_letter) {
	letter = new_letter;

	// initialize *children array
	for (int i=0; i<numCharacters; i++) {
		children[i] = NULL;
	}

	// initialize topSongs array
	for (int i=0; i<numTopSongs; i++) {
		topSong new_song;
		new_song.song_index = -1;
		new_song.freq = 0;
		topSongs[i] = new_song;
	}
}

// destructor (delete each sub-child)
wordTrieNode::~wordTrieNode() {
	for (int i=0; i<numCharacters; i++) {
		if (children[i] != NULL) {
			delete children[i];
		}
	}
}

// add new child to Node (for particular letter)
bool wordTrieNode::addChild(char new_letter) {
	// if child does not exist already
	if (children[char_to_ascii(new_letter)] == NULL) {
		wordTrieNode* new_node = new wordTrieNode(new_letter);
		children[char_to_ascii(new_letter)] = new_node;
		return true;
		
	// child already exists
	} else {
		return false;
	}
}

// returns the child according to a certain letter
wordTrieNode* wordTrieNode::getChild(char child_letter) {
	return children[char_to_ascii(child_letter)];
}

// increment the frequency for a particular song (song_index)
void wordTrieNode::incrementSong(int song_index) {
	// if there are 11 songs (including temp_song) & current song != temp
	if (topSongs[10].freq != 0 && topSongs[10].song_index != song_index) {
		// set smallest index/freq/song
		int replace_index = 10;
		int replace_song = topSongs[10].song_index;
		int replace_freq = topSongs[10].freq;
		
		// look for smallest song in topSongs
		for (int i=0;i<numTopSongs;i++) {
			if (topSongs[i].freq > 0 && 
			    topSongs[i].freq < topSongs[replace_index].freq) {
				replace_index = i;
			}
		}
		
		// swap / clear accordingly
		topSongs[replace_index].song_index = replace_song;
		topSongs[replace_index].freq = replace_freq;
		topSongs[10].song_index = -1;
		topSongs[10].freq = 0;
	}

	for (int i=0;i<numTopSongs;i++) {
		// if emptySong found, increment
		if (topSongs[i].freq == 0) {
			topSongs[i].song_index = song_index;
			topSongs[i].freq++;
			break;
		// if actualSong found, increment
		} else if (topSongs[i].song_index == song_index) {
			topSongs[i].freq++;
			break;
		}
	}
}

// sort the topSongs in decreasing order
void wordTrieNode::sortTopSongs() {
    // sort topSongs using selectionSort
    // for each song, swap with smallest song to the "right" of it
    for (int i=0;i<numTopSongs;i++) {
	// initalize smallest
        int largeInt = topSongs[i].freq;
        int largeIntSong = topSongs[i].song_index;
        int largeIntIndex = i;

	// search for smaller
        for (int j=i+1;j<numTopSongs;j++) {
            if (topSongs[j].freq > largeInt) {
                    largeInt = topSongs[j].freq;
                    largeIntSong = topSongs[j].song_index;
                    largeIntIndex = j;
            }
        }

        // adjust accordingly
        topSongs[largeIntIndex].freq = topSongs[i].freq;
        topSongs[largeIntIndex].song_index = topSongs[i].song_index;
        topSongs[i].freq = largeInt;
        topSongs[i].song_index = largeIntSong;
    }
}

// return appropriate index based on ascii value of character
int wordTrieNode::char_to_ascii(char x) {
    // return 0-25 for letters
    // return 26-36 for digits
    if (int(x) >= 97) return (int(x) - 97);
    else return (int(x) - 22);
}
