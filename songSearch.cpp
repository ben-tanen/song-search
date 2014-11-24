#include "songSearch.h"

songSearch::songSearch() {

}

songSearch::~songSearch() {

}

void songSearch::fillDatabase(const char * filename, bool show_progress) {
	ifstream in(filename);		// creates an input stream
    int song_count = 0;			// for progress indicator
	string artist, title, word;

	// -- While more data to read...
	while ( ! in.eof() ) 
	{
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;

		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;

		if ( show_progress )
		{
			
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
					" Artist: " << artist     << 
					" Title:"   << title << endl;
			}
		}

		Song new_song(artist, title);
		// -- Then read all words until we hit the 
		// -- special <BREAK> token

		while ( in >> word && word != "<BREAK>" ){
			new_song.addLyric(word);
			if (alpha_only(word).length() > 0)
				trie.addWord(alpha_only(word), song_count);	
		}
		
		// -- Important: skip the newline left behind
		in.ignore();

		// Add song to DB
		songs.push_back(new_song);
		song_count++;
	}
	return;
}

void songSearch::searchWord(string word) {
	string wordStripped = alpha_only(word);
	if (trie.hasWord(wordStripped)) {
		trie.sortTopSongs(wordStripped);
		for (int i=0; i<11; i++) {
			int index = trie.topSongN(wordStripped, i);
			if (index >= 0) {
				cout << songs[index].getTitle() << " | " << songs[index].getArtist() << endl;
				songs[index].printContext(word);
			}
		}
	}
	cout << "<END-OF-REPORT>" << endl;
}