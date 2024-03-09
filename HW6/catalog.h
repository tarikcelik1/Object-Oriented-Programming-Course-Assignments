#ifndef CATALOG_H
#define CATALOG_H

#include "exceptions.h"
#include <string>

using namespace std;

class Base_catalog{ //to define Base_catalog class.
	public:
	    static bool compare_title(const Base_catalog &c1, const Base_catalog &c2) {throw wrong_command();} //to define a boolean function for compare the title of object(book or movie or music).
	    static bool compare_authors(const Base_catalog &c1, const Base_catalog &c2) {throw wrong_command();}//to define a boolean function for compare the authors of object(book).
	    static bool compare_year(const Base_catalog &c1, const Base_catalog &c2) {throw wrong_command();}//to define a boolean function for compare the year of object(book or movie or music).
	    static bool compare_tags(const Base_catalog &c1, const Base_catalog &c2) {throw wrong_command();}//to define a boolean function for compare the tags of object(book).
	    static bool compare_artists(const Base_catalog &c1, const Base_catalog &c2) {throw wrong_command();}//to define a boolean function for compare the artists of object(music).
	    static bool compare_genre(const Base_catalog &c1, const Base_catalog &c2) {throw wrong_command();}//to define a boolean function for compare the genre of object(movie).
	    static bool compare_director(const Base_catalog &c1, const Base_catalog &c2) {throw wrong_command();}//to define a boolean function for compare the director of object(movie).
	    static bool compare_starring(const Base_catalog &c1, const Base_catalog &c2) {throw wrong_command();}//to define a boolean function for compare the starring of object(movie).
	    string get_title() const{throw wrong_command();} //to define getter function for title of object.
	    string get_authors() const{throw wrong_command();} //to define getter function for authors of object.
	    string get_year() const{throw wrong_command();} //to define getter function for year of object.
	    string get_tags() const{throw wrong_command();} //to define getter function for tags of object.
	    string get_artists() const{throw wrong_command();} //to define getter function for artists of object.
	    string get_genre() const{throw wrong_command();} //to define getter function for genre of object.
	    string get_director() const{throw wrong_command();} //to define getter function for director of object.
	    string get_starring() const{throw wrong_command();} //to define getter function for starring of object.


    };



#endif