#ifndef MUSIC_H
#define MUSIC_H

#include "catalog.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Music : public Base_catalog{ //to define Music clas which is inherited from Base_catalog class.
	public:
	    Music(); //to define default constructor.
	    Music(const vector<string> *fields); //to define with parameter constructor.
	    string get_title() const{return title;} //to define getter function for title.
	    string get_artists() const{return artists;}//to define getter function for artists.
	    int get_year() const{return year;}//to define getter function for year.
	    string get_genre() const{return genre;}//to define getter function for genre.
	    static int get_field_count() {return 4;} //to define getter funciton for fields music object has 4 data.
	    static bool compare_title(const Music &music, const Music &other_music); //to define a boolean function for compare two music object's title.
	    static bool compare_artists(const Music &music, const Music &other_music); //to define a boolean function for compare two music object's artists.
	    static bool compare_year(const Music &music, const Music &other_music); //to define a boolean function for compare two music object's year.
	    static bool compare_genre(const Music &music, const Music &other_music); //to define a boolean function for compare two music object's genre.
	    friend stringstream & operator<<(stringstream &out, const Music &music); //to define operator overload.
	private:
	    string title; //to define a string for title of music.
	    string artists; //to define a string for artists of music.
	    int year; //to define a string for year of music.
	    string genre; //to define a string for genre of music.
    };


#endif