#include "Song.h"

using namespace std;

Song::Song(string new_artist, string new_title) {
	artist = new_artist;
	title = new_title;
}

void Song::printLyrics() {
	for (vector<string>::iterator i = lyrics.begin();
                           i != lyrics.end();
                           i++)
	{
	    cout << *i << ' ';
	}
	cout << endl;
}

void Song::printSong() {
	cout << "Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	printLyrics();
}