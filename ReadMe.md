# ReadMe for COMP 15 HW6
## Song Search 
### Written by Ben Tanen

**Purpose**: The main purpose of this assignment was to be able to store and
search through a large database of songs (potentially over 170,000 songs). The
key to successfully doing this was to store and search in an efficient way. In
my particular implementation, I used a combination of vectors and tries to store
the songs and their associated data. More specific design plans can be found in
the provided `songsearch_design.txt` document.

* * *

**Included Files**: All provided files were created from scratch (with the
exclusion of `read_lyrics.cpp/.h` and parts of the `Makefile`.

`main.cpp`: This is the main file that runs the songSearch database

`songSearch.cpp`: The implementation of the songSearch DB class

`songSearch.h`: The interface of the songSearch DB class

`Song.cpp`: The implementation of the Song class (holds title/artist/lyrics)

`Song.h`: The interface of the Song class

`wordTrie.cpp`: The implementation of the wordTrie class (the main trie of A6)

`wordTrie.h`: The interface of the wordTrie class

`wordTrieNode.cpp`: The implementation of wordTrieNode class (node for wordTrie)

`wordTrieNode.h`: The interface of the wordTrieNode class

`read_lyrics.cpp`: The implementation for two provided functions

`read_lyrics.h`: The interface for alpha_only() & read_lyrics() (provided)

`songsearch_design.txt`: The initial design document for the assignment

`ReadMe.md`: The README, which gives a brief description of the program.

`Makefile`: The Makefile used to compile the program using clang++.
 
* * *

**Compile Instructions**: To compile the program, use the included Makefile.

* * *

**Data Structure(s)**: There are a few key data structures used in this
assignment that were implemented from scratch. Those include:

- songSearch: This was the main database class that held all of the songs (in a
vector) and the trie of the used words. This was the class that the main file
functions through for the sake of abstraction.
- wordTrie: This is a trie made up of words that were used in songs from this 
database. As songs are loaded in, the words of lyrics are added to the trie 
(algorithm below).
- wordTrieNode: This is a node class that is used in the main wordTrie. 
A node is used for each letter of a word. Each node holds an array of pointers 
to children nodes, a Boolean describing if the letter is an end letter, a 
pointer to an array of top 11 songs (see Song class and algorithm). For middle 
letters, the Boolean is false and the pointer is NULL. 
- topSong: This is a struct that is used in the top 11 songs array of the 
wordTrieNode. This struct holds two pieces of data: a pointer to the 
particular song (see below) and a tally of the word frequency in the song.
- Song: This is a class that is made for each song loaded in from the 
database. It holds the song title, artist, and a vector holding all of the 
lyrics (word by word, including original punctuation).

Additionally, a vector was used to store all of the Song instances (found in
the songSearch class)

* * *

**Algorithm(s)**: This assignment can be broken down into two main 
algorithms: data storage and search.

Data Storage: This process is repeated for each song loaded into the database
-> Create a new `Song`:
-> Store the artist and song title in the song
-> For each word of the lyrics:
->-> Store the lyric into song's lyric vector (at end)
->-> Trim word of any punctuation / capitalization (use alphaOnly)
->-> Add trimmed word to wordTrie [Increment frequency in top11 songs]
->->-> If there are 10 or fewer songs in the top11 array, do nothing
->->-> If new song is the 11th song in array, swap it with lowest (if needed)

At the end of this process, each word should have an array of the top 10 
(or fewer) songs that can be used in sorting.

Searching: This process is repeated for each search
-> Go through trie to find word
-> Sort associated topSongs array
-> For each song of topSongs (only top 10, in descending order):
->-> Increment through lyric vector until word found
->-> Print out previous 5 words, actual word, and next 5 words
->-> If word is placed close to front or end, adjust based on known placement