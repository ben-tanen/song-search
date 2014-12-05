//
//  songSearch.cpp
//  Class for database to hold and search songs 
//  Written by Ben Tanen
//

#include "songSearch.h"

// constructor (nothing necessary due to constructors of class variables)
songSearch::songSearch() {

}

// destructor (nothing necessary due to destructors of class variables)
songSearch::~songSearch() {

}

// reads through given file and stores song / lyric data accordingly
// original code taken from provided read_lyrics.cpp read_lyrics()
void songSearch::fillDatabase(const char * filename, bool show_progress) {
	ifstream in(filename);		// creates an input stream
	int song_count = 0;		// for progress indicator
	string artist, title, word;

	// While more data to read...
	while ( ! in.eof() ) 
	{
		// First line is the artist
		getline(in, artist);
		if (in.fail()) break;

		// Second line is the title
		getline(in, title);
		if (in.fail()) break;

		if ( show_progress ) {
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
					" Artist: " << artist     << 
					" Title:"   << title << endl;
			}
		}

		Song new_song(artist, title);
		
		// Then read all words until we hit the special <BREAK> token
		while ( in >> word && word != "<BREAK>" ){
			new_song.addLyric(word);
			// make sure lyric isn't just puncuation (like "-")
			if (alpha_only(word).length() > 0)
				trie.addWord(alpha_only(word), song_count);	
		}
		
		// Important: skip the newline left behind
		in.ignore();

		// Add song to DB
		songs.push_back(new_song);
		song_count++;
	}
	return;
}

// find a given word in the database and return the top ten songs (and context)
void songSearch::searchWord(string word) {
	// search for stripped word in trie
	string wordStripped = alpha_only(word);
	if (trie.hasWord(wordStripped)) {
		// sort topSongs in trie (decreasing order)
		trie.sortTopSongs(wordStripped);

		for (int i=0; i<10; i++) {
			// index of song returned from topSongs array
			int index = trie.topSongN(wordStripped, i);
			
			// if index is actual index (will return -1 if not)
			if (index >= 0) {
				songs[index].printContext(word);
			}
		}
	}
	cout << "<END OF REPORT>" << endl;
}
