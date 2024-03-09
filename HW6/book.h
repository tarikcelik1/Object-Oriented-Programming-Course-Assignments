#ifndef BOOK_H
#define BOOK_H

#include "catalog.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Book : public Base_catalog{ //to define Book clas which is inherited from Base_catalog class.
	public:
	    Book(); //to define default constructor.
	    Book(const vector<string> *fields);//to define with parameter constructor.
	    string get_title() const{return title;} //to define getter function for title.
	    string get_authors() const{return authors;}//to define getter function for authors.
	    int get_year() const{return year;}//to define getter function for year.
	    string get_tags() const{return tags;}//to define getter function for tags.
	    static int get_field_count() {return 4;} //to define getter funciton for fields book object has 4 data.
	    static bool compare_title(const Book &book, const Book &other_book); //to define a boolean function for compare two book object's title.
	    static bool compare_authors(const Book &book, const Book &other_book);//to define a boolean function for compare two book object's authors.
	    static bool compare_year(const Book &book, const Book &other_book);//to define a boolean function for compare two book object's year.
	    static bool compare_tags(const Book &book, const Book &other_book);//to define a boolean function for compare two book object's tags.
	    friend stringstream & operator<<(stringstream &out, const Book &book);//to define operator overload.
	private:
	    string title; //to define a string for title of book.
	    string authors; //to define a string for authors of book.
	    int year; //to define a string for year of book.
	    string tags; //to define a string for tags of book.
    };

#endif