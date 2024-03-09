#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "book.h"
#include "music.h"
#include "movie.h"
#include "catalog.h"

using namespace std;

vector<string> * get_string_between_quotes(const string &str, char delimiter){ //to define get_string_between_quotes.
/*
* This function takes a string and a character as a parameter and it finds strings in between given character in given string.
* It returns a vector (list) of founded strings.
*/
    vector<string> *getstr = new vector<string>(); //to define a string vector for founded stirngs.
    bool flag = false;	//to define a boolean variable for checking adding string in vector.
    for(auto iterator = str.begin(); iterator != str.end(); ++iterator){	//to create a loop for iterating string.
		if(*iterator == delimiter){	//to check iterator is equal to given delimiter char or not.
	    	flag = !flag;
	    	if(flag)		//to checking flag and adding string to the vector.
				getstr->insert(getstr->begin(),"");   //to add string to the vector.
		}	
		else if(flag)
	    	getstr->front() += *iterator;
    }
    return getstr; //to return created vector of strings.
}

template <typename T>
void read_data_from_file(ifstream &in, vector<T> &list, ofstream &out) { //to define read_data_from_file function.
/*
* This function takes two file one for read other one for write and takes a template vector for create a list.
* It reads file and it checks missing field exception and duplicate entry exception and it counts the unique entries in file
*   then it creates a list of objects in file.
* It also writes the exceptions and number of unique entry to the output file.
*/
    string read_line;//to define a string for readed line.
    int unique_entries = 0;//to define a integer for unique entries in file.
    string first_field;//to define string fro firs field in lines.
    vector<string> *fields;//to define vector of strings for reading file.
    int field_counter;//to define an integer to count the fields and use it for missing field exception.
    while(getline(in, read_line)){ //to create a loop for read the given file.
		fields = get_string_between_quotes(read_line, '"'); //to get string between the quotes.
		field_counter = 0;//to reset the field counter for every line of file.
		try{
	    	for(auto iterator = fields->begin(); iterator != fields->end(); ++iterator){	//to create a loop for iterate the fields string.
				first_field = *iterator;   //to assign fiers field string to iterator.
				++field_counter;	    //to increase field counter by one for every iteration.
	    	}
	    	if(field_counter != T::get_field_count())    //to check field counter is equal to object's(book or movie or music) number of field.
				throw missing_field();		    //to throw missing field exception.
		}
		catch(missing_field e){ //to catch the missing field exception.
	    	out << "Exception: " << e.what() << endl //to write the exception information to the output file.
			<< read_line << endl;
	    	delete fields;
	    	continue; //to go to read next line of given file.
		}
		try{
	    	for(auto iterator = list.begin(); iterator != list.end(); ++iterator){ //to create a loop for iterate each object in the list.
				if(iterator->get_title() == first_field) //to check is there two same titled object.
		    		throw duplicate_entry(); //if there is same titled two object then throw the duplicate entry exception.
	    	}
		}
		catch(duplicate_entry e){ //to catch the dupliacte entry exception.
	    	out << "Exception: " << e.what() << endl //to write the exception information to the output file.
			<< read_line << endl;
	    	delete fields;
	    	continue; //to go to read next line of given file.
		}
		++unique_entries; //to increase number of unique entries by one for each unique line of file.
		list.insert(list.begin(),fields); //to add object which is instantly readed from fiel to the list.
		delete fields;
    }
    out << unique_entries << " unique entries\n"; //to write number of unique entries to the output file.
}


template <typename T>
void apply_commands_in_file(ifstream &in, vector<T> &list_of_data, ofstream &out){ //to define apply_commands_in_file function.
/*
* This function takes two file one for read one for write and a vector which is list of the objects' datas.
* This function reads commands file and it apply that commands in list which is created from a data file.
* Then it writes results of the commands to the output file.
*/
string read_line; //to define a string for readed line.
vector<string> *fields; //to define vector of strings for reading file.
while(getline(in, read_line)){ //to create a loop for read the given commands file.
	stringstream streamread_line(read_line);	//to create stream of read line to get what command is written.
	stringstream output_string;		//to create string for result string of the command.
	fields = get_string_between_quotes(read_line, '"'); //to get string between the quotes.
	auto command_argument = fields->begin();	//to define a iterator for command's argument.
	string command;	//to define a strign for command.
	streamread_line >> command;	//to get command.
	string searched_field_of_catalog = *command_argument++; //to get serach or sort field of file.
	try{
	    if(command == "search"){ //this if block is for search command.
			string searched = *command_argument++; //to define a string for serched word.
			if(searched_field_of_catalog == "title"){ //this if block for title search.
		    	for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator){ //to create a loop for iterating through the string.
					if(iterator->get_title().find(searched) != string::npos) //to check is there any matching title with searched.
			    		output_string << *iterator; //command result.
		    	}
			}
			else if(searched_field_of_catalog == "authors"){ //this if block for authors search.
		    	for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator){ //to create a loop for iterating through the string.
					if(iterator->get_authors().find(searched) != string::npos) //to check is there any matching authors with searched.
			    		output_string << *iterator; //command result.
		    	}
			}
			else if(searched_field_of_catalog == "year"){ //this if block for year search.
		    	for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator){ //to create a loop for iterating through the string.
					if(to_string(iterator->get_year()).find(searched) != string::npos) //to check is there any matching year with searched.
			    		output_string << *iterator; //command result.
		    	}
			}
			else if(searched_field_of_catalog == "tags"){ //this if block for tags search.
		    	for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator){ //to create a loop for iterating through the string.
					if(iterator->get_tags().find(searched) != string::npos) //to check is there any matching tags with searched.
			    		output_string << *iterator; //command result.
		    	}
			}
			else if(searched_field_of_catalog == "artists"){ //this if block for artists search.
		    	for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator){ //to create a loop for iterating through the string.
					if(iterator->get_artists().find(searched) != string::npos) //to check is there any matching artists with searched.
			    		output_string << *iterator;  //command result.
		   		}
			}
			else if(searched_field_of_catalog == "genre"){ //this if block for genre search.
		    	for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator){ //to create a loop for iterating through the string.
					if(iterator->get_genre().find(searched) != string::npos) //to check is there any matching genre with searched.
			    		output_string << *iterator; //command result.
		    	}
			}
			else if(searched_field_of_catalog == "director"){ //this if block for director search.
		    	for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator){ //to create a loop for iterating through the string.
					if(iterator->get_director().find(searched) != string::npos) //to check is there any matching directtor with searched.
			    		output_string << *iterator;//command result.
		    	}
			}
			else if(searched_field_of_catalog == "starring"){ //this if block for starring search.
		    	for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator){ //to create a loop for iterating through the string.
					if(iterator->get_starring().find(searched) != string::npos) //to check is there any matching starring with searched.
			    		output_string << *iterator; //command result.
		    	}
			}
			else //if not in given fields then it is a wrong command.
		    	throw wrong_command(); //to throw wrong command exception.
	    }
	    else if(command == "sort"){	//this if block for sort command.
			if(searched_field_of_catalog == "title") //this if for sort by title.
		    	sort(list_of_data.begin(),list_of_data.end(),T::compare_title); //to sort list of data by title with using sort function of vectors.
			else if(searched_field_of_catalog == "authors") //this if for sort by authors.
		    	sort(list_of_data.begin(),list_of_data.end(),T::compare_authors); //to sort list of data by authors with using sort function of vectors.
			else if(searched_field_of_catalog == "year") //this if for sort by year.
		    	sort(list_of_data.begin(),list_of_data.end(),T::compare_year); //to sort list of data by year with using sort function of vectors.
			else if(searched_field_of_catalog == "tags") //this if for sort by tags.
		    	sort(list_of_data.begin(),list_of_data.end(),T::compare_tags); //to sort list of data by tags with using sort function of vectors.
			else if(searched_field_of_catalog == "artists") //this if for sort by artists.
		    	sort(list_of_data.begin(),list_of_data.end(),T::compare_artists); //to sort list of data by artists with using sort function of vectors.
			else if(searched_field_of_catalog == "genre") //this if for sort by genre.
		    	sort(list_of_data.begin(),list_of_data.end(),T::compare_genre); //to sort list of data by genre with using sort function of vectors.
			else if(searched_field_of_catalog == "director") //this if for sort by director.
		    	sort(list_of_data.begin(),list_of_data.end(),T::compare_director); //to sort list of data by director with using sort function of vectors.
			else if(searched_field_of_catalog == "starring") //this if for sort by starring.
		    	sort(list_of_data.begin(),list_of_data.end(),T::compare_starring); //to sort list of data by starring with using sort function of vectors.
			else //if not in given fields then it is a wrong command.
		    	throw wrong_command(); //to throw wrong command exception.
		
			for(auto iterator = list_of_data.begin(); iterator != list_of_data.end(); ++iterator)
		    	output_string << *iterator; //to create command result.
	    }
	}
	catch(wrong_command e){	//to catch wrong command exception.
	    out << "Exception: " << e.what() << endl //to write wrong command exception information to the output file.
		<< read_line << endl;
	    delete fields;
	    continue; //to go to read next line of command file and apply them.
	}

	out << read_line << endl //to write read line to output file.
	    << output_string.str();	//to write result of command informartion to the output file.
	delete fields;
    }
}

int main(){

    ifstream file_of_data("data.txt"); //to open data.txt file for reading.
	ifstream command_file("commands.txt"); //to open commands.txt file for reading.
    ofstream output_file("output.txt"); //to open output.txt file for writing.
    string type_of_catalog; //to define a string for store the type of catalog.
    getline(file_of_data, type_of_catalog); //to get first line of data.txt file which is about type of catalog.(music,movie,book).
    if(type_of_catalog == "book"){ //this if block for book type catalog.
	    output_file << "Catalog Read : book"<<endl; //to write catalog type to the first line of output.txt file. 
	    vector<Book> list_of_data; //to create a vector of Book objects.
	    read_data_from_file<Book>(file_of_data, list_of_data, output_file);	//to read data from file and store it in vector with using read_data_from_file function.
	    apply_commands_in_file<Book>(command_file, list_of_data, output_file); //to call apply_commands_in_file function.
    }
    else if(type_of_catalog == "music"){ //this if block for music type catalog.
	    output_file << "Catalog Read : music"<<endl; //to write catalog type to the first line of output.txt file. 
	    vector<Music> list_of_data; //to create a vector of Music objects.
	    read_data_from_file<Music>(file_of_data, list_of_data, output_file); //to read data from file and store it in vector with using read_data_from_file function.
	    apply_commands_in_file<Music>(command_file, list_of_data, output_file); //to call apply_commands_in_file function.
    }
    else if(type_of_catalog == "movie"){ //this if block for movie type catalog.
	    output_file << "Catalog Read : movie"<<endl; //to write catalog type to the first line of output.txt file.
	    vector<Movie> list_of_data; //to create a vector of Movie objects.
	    read_data_from_file<Movie>(file_of_data, list_of_data, output_file); //to read data from file and store it in vector with using read_data_from_file function.
	    apply_commands_in_file<Movie>(command_file, list_of_data, output_file); //to call apply_commands_in_file function.
    }
    file_of_data.close();
    output_file.close();  //to close all the .txt files.
    command_file.close();
    return 0;
}
