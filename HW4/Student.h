#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Course.h"

using namespace std;

namespace PA4 {
    class Course;
    class Student {
    public:
        Student(); //to define default constructor of Student class.
        Student(const string& name1, int id1); //to define with parameter constructor.
        ~Student(); //To define destroctor.

        const string& getName() const;
        int getID() const;                         //to define getter functions for private data member of class.
        Course** getCourses() const;
        int getNumCourses() const;

        void setName(const string& name1);     //to define setter functions for private data member of class.
        void setID(int id);
        void addCourse(Course* course);  //to define addCourse function.
        void removeCourse(Course* course);  //to define removeCourse function
    private:
        string name;
        int id;
        Course** courses;   //to define private data members of class.
        int numCourses;
    };
}
#endif