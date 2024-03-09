#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

using namespace std;

    class Exception{ //to define Exceptions.
    };

    class missing_field : public Exception{ //to define missing field exception.
	public:
	    string what() const {return "missing field";}
    };

    class duplicate_entry : public Exception{ //to define duplicate entry exception.
	public:
	    string what() const {return "duplicate entry";}
    };

    class wrong_command : public Exception{ //to define wrong command exception.
	public:
	    string what() const {return "command is wrong";}
    };

#endif
