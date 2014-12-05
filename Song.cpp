//
//  Song.cpp
//  Class to hold data associated with different songs (lyrics, title, artist)
//  Written by Ben Tanen
//

#include "Song.h"

using namespace std;

// constructor class (store new_artist / new_title)
Song::Song(string new_artist, string new_title) {
	artist = new_artist;
	title = new_title;
}

// print every lyric of a particular song (used for testing purposes)
void Song::printLyrics() {
	// vector iterator for each lyric
	for (vector<string>::iterator i = lyrics.begin();
                           i != lyrics.end();
                           i++)
	{
	    cout << *i << ' ';
	}
	cout << endl;
}

// print full content of song (title, artist, lyrics) (used for testing)
void Song::printSong() {
	cout << "Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	printLyrics();
}

// print all of the occasions when a word appears (and context)
void Song::printContext(string word) {
	// search through every word
	for (int i=0; i<lyrics.size(); i++) {
		// if stripped word is same as stripped lyric
		if (alpha_only(lyrics[i]) == alpha_only(word)) {
			cout << "Title: " << title << endl;
			cout << "Artist: " << artist << "\nContext: " ;
			// previous 5 words to next 5 words
			for (int j=i-5;j<i+6;j++) {
				// if index is inside scope of lyrics, print
				if (j >= 0 && j < lyrics.size()) {
					cout << lyrics[j] << ' ';
				}
			}
			cout << endl << endl;
		}
	}
	
}