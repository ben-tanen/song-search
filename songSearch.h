//
//  songSearch.h
//  Class for database to hold and search songs 
//  Written by Ben Tanen
//

#ifndef __songSearch_h__
#define __songSearch_h__

#include "wordTrie.h"
#include "Song.h"
#include "read_lyrics.h"

#include <iostream>
#include <sstream>
#include <fstream>

class songSearch {
	public:
		songSearch();
		~songSearch();
		void fillDatabase(const char * filename, bool show_progress);
		void searchWord(string word);

	private:
		// vector to store songs (titles, artists, unstripped lyrics)
		vector<Song> songs;
		
		// trie to hold sorted / stripped lyrics
		wordTrie trie;
};

#endif

