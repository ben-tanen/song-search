//
//  Song.h
//  Class to hold data associated with different songs (lyrics, title, artist)
//  Written by Ben Tanen
//

#ifndef __Song_h__
#define __Song_h__

#include <iostream>
#include <vector>
#include "read_lyrics.h"

using namespace std;

class Song {
    public:
        Song(string artist, string title);
	
	// setters/getters for artists/title/lyrics, used for song testing 
	void   setArtist(string new_artist) { artist = new_artist; }
	void   setTitle(string new_title) { title = new_title; }
	void   setLyric(int n, string new_lyric) { lyrics[n] = new_lyric; }
	string getArtist() { return artist; }
	string getTitle()  { return title; }
	string getLyric(int n) { return lyrics[n]; }
	
	// add new lyric to end of lyrics vector
	void   addLyric(string new_lyric) { lyrics.push_back(new_lyric); }
	
	// print the lyrics, full song, and lyric context for song
	void   printLyrics();
	void   printSong();
	void   printContext(string word);

    private:
	string artist;
	string title;
	vector<string> lyrics;
};

// struct used in array of topSongs for each wordTrieNode
// holds the index of a song and the freq of a word within it
struct topSong {
	int song_index;
	int freq;
};

#endif