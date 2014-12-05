#include <iostream>
#include "songSearch.h"

using namespace std;

int main(int argc, char const *argv[])
{
	songSearch database;

    string file_name = "full_db.txt";
    
    if (argc > 1) {
        file_name = argv[1];
    }
    
    bool   show_progress = true;
	database.fillDatabase(file_name.c_str(),show_progress);

	string search_word;
	while (cin >> search_word && search_word != "<BREAK>") {
		database.searchWord(search_word);
	}

    return 0;
}