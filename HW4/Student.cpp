#include "Student.h"
#include <string>

using namespace std;

namespace PA4 {
    Student::Student() : name(""), id(0), courses(nullptr), numCourses(0) {} //to create default constructor of Student class.

    Student::Student(const string& name1, int id1) : name(name1), id(id1), courses(nullptr), numCourses(0) {} //to define with parameter constructor.

    Student::~Student() { //To define destroctor.
        for (int i = 0; i < numCourses; i++) {
            courses[i]->removeStudent(this); //to remove the destructed student from courses.
        }
        delete[] courses;
    }

    const string& Student::getName() const { return name; }

    int Student::getID() const { return id; }              //to define getter functions for privata data members of class.

    Course** Student::getCourses() const { return courses; }

    int Student::getNumCourses() const { return numCourses; }

    void Student::setName(const string& name1) { name = name1; }     //to define setter functions for privata data members of class.

    void Student::setID(int id1) { id = id1; }

    void Student::addCourse(Course* course) {//to define addCourse function.
    /*
    * This function takes a course object as a parmaeter and it adds that course to student class.
    */
        Course** coursearr = new Course*[numCourses+1];
        for(int i=0;i<numCourses;i++){
            coursearr[i] = courses[i];
        }
        delete []courses;
        courses = coursearr;
        courses[numCourses++] = course;
  
    }

    void Student::removeCourse(Course* course) { //to define removeCourse function
    /*
    * This function takes a course object as a parmaeter and it removes that course from student class.
    */    
        int index = -1;
        for (int i = 0; i < numCourses; i++) {
            if (courses[i] == course) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return;
        }
        for (int i = index; i < numCourses - 1; i++) {
            courses[i] = courses[i + 1];
        }
        numCourses--;
        course->removeStudent(this);
    }
}