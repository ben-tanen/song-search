//
//  main.cpp
//  main file associated with songSearch assignment
//  Written by Ben Tanen
//

#include <iostream>
#include "songSearch.h"

using namespace std;

int main(int argc, char const *argv[])
{
    songSearch database;

    // initialize standard file_name / show_progress / search_word
    string file_name = "full_db.txt";
    bool show_progress = false;
    string search_word;
    
    // if user passed alternate filename
    if (argc > 1) {
        file_name = argv[1];
    }

    if (argc > 2) {
        show_progress = true;
    }
    
    // fill database using parameters above
	database.fillDatabase(file_name.c_str(),show_progress);

    // until <BREAK> search for word
    while (cin >> search_word && search_word != "<BREAK>") {
	database.searchWord(search_word);
    }

    return 0;
}