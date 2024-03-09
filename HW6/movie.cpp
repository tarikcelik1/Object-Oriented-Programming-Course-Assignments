#include "movie.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;
    
Movie::Movie() : title{}, director{}, year{}, genre{}, starring{}{}//to define default constructor of Movie class.    
Movie::Movie(const vector<string> *fields){ //to define with parameter constructor.
	auto iterator = fields->begin(); //to define a iterator for get string in fields vector.
	starring = *iterator++;
	genre = *iterator++;
	year = stoi(*iterator++);
	director = *iterator++;
	title = *iterator++;
}
    
bool Movie::compare_title(const Movie &movie, const Movie &other_movie) { //to define a boolean function for compare two movie object's title.
	if(movie.title.compare(other_movie.title) > 0) //to compare title string with using string comparison function.
       return false;
    return true;
    }

bool Movie::compare_director(const Movie &movie, const Movie &other_movie) { //to define a boolean function for compare two movie object's director.
	if(movie.director.compare(other_movie.director) > 0) //to compare director string with using string comparison function.
       return false;
    return true;
    }

bool Movie::compare_year(const Movie &movie, const Movie &other_movie) { //to define a boolean function for compare two movie object's year.
   if(movie.year < other_movie.year) //to compare year.
       return true;
   return false;
    }
    
bool Movie::compare_genre(const Movie &movie, const Movie &other_movie) { //to define a boolean function for compare two movie object's genre.
   if(movie.genre.compare(other_movie.genre) > 0) //to compare genre string with using string comparison function.
       return false;
   return true;
    }

bool Movie::compare_starring(const Movie &movie, const Movie &other_movie) { //to define a boolean function for compare two movie object's starring.
   if(movie.starring.compare(other_movie.starring) > 0) //to compare starring string with using string comparison function.
       return false;
   return true;
    }

stringstream & operator<<(stringstream &out, const Movie &movie){ //to define operator overload.
	    out << '"' << movie.title << "\" \"" << movie.director << "\" \"" << movie.year << "\" \"" 
	        << movie.genre << "\" \"" << movie.starring << '"' << endl;
	    return out;
    }
