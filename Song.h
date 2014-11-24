#ifndef __Song_h__
#define __Song_h__

#include <iostream>
#include <vector>
#include "read_lyrics.h"

using namespace std;

class Song {
	public:
		Song(string artist, string title);
		void   setArtist(string new_artist) { artist = new_artist; }
		void   setTitle(string new_title) { title = new_title; }
		void   editLyric(int place, string new_lyric) { lyrics[place] = new_lyric; }
		void   addLyric(string new_lyric) {lyrics.push_back(new_lyric); }
		string getArtist() { return artist; }
		string getTitle()  { return title; }
		string getLyric(int n) { return lyrics[n]; }
		void   printLyrics();
		void   printSong();
		void   printContext(string word);

	private:
		string artist;
		string title;
		vector<string> lyrics;
};

struct topSong {
	int song_index;
	int freq;
};

#endif