#include <iostream>
#include "Song.h"

using namespace std;

int main(int argc, char const *argv[])
{
	string lyrics[10] = {
		"I", "wanna", "takee", "you", "somewhere", "so", "you", "know", "I", "care"
	};

	Song new_song("Tom Odell", "Another Love");
	
	for (int i=0; i<10; i++) {
		new_song.addLyric(lyrics[i]);
	}

	topSong top1;
	top1.song = &new_song;
	top1.freq = 15;

	top1.song->printSong();
	new_song.editLyric(2, "take");
	new_song.printLyrics();

	return 0;
}