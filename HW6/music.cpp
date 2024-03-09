#include "music.h"
#include "catalog.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Music::Music() : title{}, artists{}, year{}, genre{}{} //to define default constructor.
Music::Music(const vector<string> *fields){ //to define with parameter constructor.
	auto iterator = fields->begin();  //to define a iterator for get string in fields vector.
	genre = *iterator++;	
	year = stoi(*iterator++);	
	artists = *iterator++;	
	title = *iterator++;	
}
    
bool Music::compare_title(const Music &music, const Music &other_music) { //to define a boolean function for compare two music object's title.
	if(music.title.compare(other_music.title) > 0) //to compare title string with using string comparison function.
       return false;
    return true;
}

bool Music::compare_artists(const Music &music, const Music &other_music) { //to define a boolean function for compare two music object's artists.
	if(music.artists.compare(other_music.artists) > 0) //to compare artists string with using string comparison function.
       return false;
    return true;
}

bool Music::compare_year(const Music &music, const Music &other_music) { //to define a boolean function for compare two music object's year.
	if(music.year < other_music.year) //to compare year.
    	return true;
    return false;
}
    
bool Music::compare_genre(const Music &music, const Music &other_music) { //to define a boolean function for compare two music object's genre.
	if(music.genre.compare(other_music.genre) > 0) //to compare genre string with using string comparison function.
       return false;
    return true;
}

stringstream & operator<<(stringstream &out, const Music &music){ //to define operator overload.
	out << '"' << music.title << "\" \"" << music.artists << "\" \"" << music.year << "\" \"" 
	    << music.genre << '"' << endl;
	return out;
}
