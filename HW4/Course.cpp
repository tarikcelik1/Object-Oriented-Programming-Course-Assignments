#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

namespace PA4 {
    Course::Course() : name(""), code(""), students(nullptr), numofstudents(0) {} //to define default constructor of Course class.

    Course::Course(const string& name, const string& code) : name(name), code(code), students(nullptr), numofstudents(0){} //to define with parameter constructor.

    Course::~Course() { //to define destructor.
        for (int i = 0; i < numofstudents; i++) {
            students[i]->removeCourse(this); //to remove the destructed course from students.
        }
        delete[] students;
    }

    const string& Course::getName() const { //to define getter function for name variable of class.
        return name;
    }

    const string& Course::getCode() const { //to define getter function for code variable of class.
        return code;
    }

    Student** Course::getStudents() const { //to define getter function for students  of class.
        return students;
    }

    int Course::getNumStudents() const { //to define getter function for number of students variable of class.
        return numofstudents;
    }

    void Course::setName(const string& name1) { //to define setter function for name variable of class.
        name = name;
    }

    void Course::setCode(const string& code1) { //to define setter function for code variable of class.
        code = code1;
    }

    void Course::addStudent(Student* student) { //to define addStudent function.
    /*
    * This function takes a student object as a parameter and it enrolls that student to course.
    */
        Student** studentarr = new Student*[numofstudents+1]; //to size up the dynamic allocated memory.
        for(int i=0;i<numofstudents;i++){
            studentarr[i] = students[i];
        }
        delete []students;
        students = studentarr;
        students[numofstudents++] = student;

    }

    void Course::removeStudent(Student* student) { //to define removeStudent function.
        /*
        * This function takes a student object as a parameter and it removes that student from course.
        */
        int index = -1;
        for (int i = 0; i < numofstudents; i++) {
            if (students[i] == student) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return;
        }
        for (int i = index; i < numofstudents - 1; i++) {
            students[i] = students[i + 1];
        }
        numofstudents--;
        student->removeCourse(this);
    }
    int Course::hasRegistered(Student* student){ //to define hasRegistered function.
    /*
    * This function takes a student object as a parameter and it checks that student registered to course or not.
    * It returns 1 if that student is registered to course otherwise it returns 0.
    */
        for(int i=0;i<numofstudents;i++){
            if(students[i] == student) return 1;
        }
        return 0;
    }
}