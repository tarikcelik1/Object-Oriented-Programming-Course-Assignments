#ifndef MOVIE_H
#define MOVIE_H

#include "catalog.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Movie : public Base_catalog{  //to define Movie class which is inherited from Base_catalog class.
	public:
	    Movie(); //to define default constructor.
	    Movie(const vector<string> *fields); //to define with parameter constructor.
	    string get_title() const{return title;} //to define getter function for title.
	    string get_director() const{return director;} //to define getter function for director.
	    int get_year() const{return year;} //to define getter function for year.
	    string get_genre() const{return genre;} //to define getter function for genre.
	    string get_starring() const{return starring;} //to define getter function for starring.
	    static int get_field_count() {return 5;} //to define getter funciton for fields movie object has 5 data.
	    static bool compare_title(const Movie &movie, const Movie &other_movie); //to define a boolean function for compare two movie object's title.
	    static bool compare_director(const Movie &movie, const Movie &other_movie); //to define a boolean function for compare two movie object's director.
	    static bool compare_year(const Movie &movie, const Movie &other_movie); //to define a boolean function for compare two movie object's year.
	    static bool compare_genre(const Movie &movie, const Movie &other_movie); //to define a boolean function for compare two movie object's genre.
	    static bool compare_starring(const Movie &movie, const Movie &other_movie); //to define a boolean function for compare two movie object's starring.
	    friend stringstream & operator<<(stringstream &out, const Movie &movie);//to define operator overload.
	private:
	    string title; //to define a string for title of movie.
	    string director; //to define a string for director of movie.
	    int year; //to define a string for year of movie.
	    string genre; //to define a string for genre of movie.
	    string starring; //to define a string for starring of movie.
    };


#endif