#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"

using namespace std;

namespace PA4 { //to define classes under the PA4 namespace.
    class Student;
    class Course {
    public:
        Course(); //to define default constructor.
        Course(const string& name, const string& code); //to define constructor with parameter.
        ~Course(); //to define destructor.

        const string& getName() const;
        const string& getCode() const;    //to define getter functions of the class.
        Student** getStudents() const;
        int getNumStudents() const;

        void setName(const string& name);
        void setCode(const string& code);  //to define setter function of the class.

        void addStudent(Student* student); //to define addStudent function as a member of Course class.
        void removeStudent(Student* student); //to define removeStudent function as a member of Course class.
        int hasRegistered(Student* student); //to define hasRegistered function as a member of Course class.
    private:
        string name; //to define private member of class which is name.
        string code; //to define private member of class which is code.
        Student** students; //to define private member of class which is students.
        int numofstudents; //to define private member of class which is numofstudents.
        
    };
}
#endif