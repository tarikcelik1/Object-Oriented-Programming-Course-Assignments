#include "book.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Book::Book() : title{}, authors{}, year{}, tags{}{} //to define default constructor of Book class   
Book::Book(const vector<string> *fields) {//to define with parameter constructor.
	auto iterator = fields->begin(); //to define a iterator for get string in fields vector.
	tags = *iterator++;
	year = stoi(*iterator++);
	authors = *iterator++;
	title = *iterator++;
}

bool Book::compare_title(const Book &book, const Book &other_book) { //to define a boolean function for compare two book object's title.
    if(book.title.compare(other_book.title) > 0) //to compare title string with using string comparison function.
        return false;
    return true;
    }

bool Book::compare_authors(const Book &book, const Book &other_book) {//to define a boolean function for compare two book object's authors.
    if(book.authors.compare(other_book.authors) > 0)//to compare authors string with using string comparison function.
        return false;
    return true;
    }

bool Book::compare_year(const Book &book, const Book &other_book) {//to define a boolean function for compare two book object's year.
    if(book.year < other_book.year) //to compare year.
        return true;
    return false;
    }
    
bool Book::compare_tags(const Book &book, const Book &other_book) {//to define a boolean function for compare two book object's tags.
    if(book.tags.compare(other_book.tags) > 0)//to compare tags string with using string comparison function.
        return false;
    return true;
    }

stringstream & operator<<(stringstream &out, const Book &book){ //to define operator overload.
	out << '"' << book.title << "\" \"" << book.authors << "\" \"" << book.year << "\" \"" 
	    << book.tags << '"' << endl;
	return out;
    }