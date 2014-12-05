#include "wordTrieNode.h"

using namespace std;

wordTrieNode::wordTrieNode() {
	for (int i=0; i<numCharacters; i++) {
		children[i] = NULL;
	}

	for (int i=0; i<numTopSongs; i++) {
		topSong new_song;
		new_song.song_index = -1;
		new_song.freq = 0;
		topSongs[i] = new_song;
	}
}

wordTrieNode::wordTrieNode(char new_letter) {
	letter = new_letter;

	for (int i=0; i<numCharacters; i++) {
		children[i] = NULL;
	}

	for (int i=0; i<numTopSongs; i++) {
		topSong new_song;
		new_song.song_index = -1;
		new_song.freq = 0;
		topSongs[i] = new_song;
	}
}

wordTrieNode::~wordTrieNode() {
	for (int i=0; i<numCharacters; i++) {
		if (children[i] != NULL) {
			delete children[i];
		}
	}
}

bool wordTrieNode::addChild(char new_letter) {
	if (children[char_to_ascii(new_letter)] == NULL) {
		wordTrieNode* new_node = new wordTrieNode(new_letter);
		children[char_to_ascii(new_letter)] = new_node;
		return true;
	} else {
		return false;
	}
}

wordTrieNode* wordTrieNode::getChild(char child_letter) {
	return children[char_to_ascii(child_letter)];
}

void wordTrieNode::incrementSong(int song_index) {
	if (topSongs[10].song_index != song_index && topSongs[10].freq != 0) {
		int smallest_freq = 10;
		int replace_song = topSongs[10].song_index;
		int replace_freq = topSongs[10].freq;
		for (int i=0;i<numTopSongs;i++) {
			if (topSongs[i].freq < topSongs[smallest_freq].freq) {
				smallest_freq = i;
			}
		}
		topSongs[smallest_freq].song_index = replace_song;
		topSongs[smallest_freq].freq = replace_freq;
	}

	for (int i=0;i<numTopSongs;i++) {
		if (topSongs[i].freq == 0) {
			topSongs[i].song_index = song_index;
			topSongs[i].freq++;
			break;
		} else if (topSongs[i].song_index == song_index) {
			topSongs[i].freq++;
			break;
		}
	}
}

void wordTrieNode::sortTopSongs() {
	for (int i=0;i<numTopSongs;i++) {
        int largeInt = topSongs[i].freq;
        int largeIntSong = topSongs[i].song_index;
        int largeIntIndex = i;

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

int wordTrieNode::char_to_ascii(char x) {
    // return 0-25 for letters
    // return 26-36 for digits
    if (int(x) >= 97) return (int(x) - 97);
    else return (int(x) - 22);
}
