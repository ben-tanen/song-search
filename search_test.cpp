#include <iostream>
#include "songSearch.h"

using namespace std;

int main(int argc, char const *argv[])
{
	
	songSearch database;
	database.fillDatabase("rick_db.txt",false);

	string search_word;
	while (cin >> search_word && search_word != "<BREAK>") {
		database.searchWord(search_word);
	}

	return 0;
}