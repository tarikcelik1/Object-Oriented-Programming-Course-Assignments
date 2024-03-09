#include "SchoolManagerSystem.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

namespace PA4 { //to define classes under the PA4 namespace.
    SchoolManagerSystem::SchoolManagerSystem() { //to define default constructor of SchoolManagerSystem calss.
        students = new Student*[5];
        courses = new Course*[5];
        numStudents = 0;
        numCourses = 0;
    }

    SchoolManagerSystem::~SchoolManagerSystem() { //to define destructor of SchoolManagerSystem class.
        for (int i = 0; i < numStudents; i++) {
            delete students[i];
        }
        for (int i = 0; i < numCourses; i++) {
            delete courses[i];
        }
        delete[] students; //to delete dynamically alloocated memory.
        delete[] courses;
    }

    void SchoolManagerSystem::addStudent(const string& name, int id) { //to define addStudent function.
    /*
    * This function takes name and  id as a parameter and it creates a student object with given parameters.
    * Then it stores the student object in school management system class.
    * If dynamic memory is not allocated then it allocate it.
    */
        Student** studentarr = new Student*[numStudents+1]; //to size up the dynamic allocated memory.
        for(int i=0;i<numStudents;i++){
            studentarr[i] = students[i];
        }
        delete []students;
        students = studentarr;
        students[numStudents] = new Student(name, id); //to add new student to dynamic array.
        numStudents++; //to increase the number of students variable by 1.
    }

    int SchoolManagerSystem::selectStudent(const string& name, int id) { //to define select student function.
    /*
    * This function takes name and id parameter and it finds the student which is given in parameter.
    * Then it assigns index to that student's index.
    * If it that student exists it returns 1 otherwise retruns 0.
    */
        for (int i = 0; i < numStudents; i++) { //to create a for loop for find the student.
            if (students[i]->getID() == id) {
                currentStudentIndex = i;
                return 1;
            }
        }
        return 0;
    }

    void SchoolManagerSystem::deleteStudent() { //to define delete student function.
    /*
    * This function deletes the selected student from school.
    */
        delete students[currentStudentIndex];
        numStudents--;
        for (int i = currentStudentIndex; i < numStudents; i++) { 
            students[i] = students[i+1];
        }
    }

    void SchoolManagerSystem::addCourse(const string& name, const string& code) { //to define addCourse function.
    /*
    * This function takes name and  code as a parameter and it creates a course object with given parameters.
    * Then it stores the course object in school management system class.
    * If dynamic memory is not allocated then it allocate it.
    */
        Course** coursearr = new Course*[numCourses+1]; //to size up the dynamic allocated memory.
        for(int i=0;i<numCourses;i++){
            coursearr[i] = courses[i];
        }
        delete []courses;
        courses = coursearr;

        courses[numCourses] = new Course(name, code);//to add new course to dynamic array.
        numCourses++; //to increase the number of students variable by 1.
    }

    int SchoolManagerSystem::selectCourse(const string& code) { //to define select course function.
    /*
    * This function takes code parameter and it finds the course which is given in parameter.
    * Then it assigns index to that courses' index.
    * If it that course exists it returns 1 otherwise retruns 0.
    */
        for (int i = 0; i < numCourses; i++) { //to create a for loop for find the course.
            if (courses[i]->getCode() == code) {
                currentCourseIndex = i;
                return 1;
            }
        }
        return 0;
    }

    void SchoolManagerSystem::deleteCourse() { //to define delete course function.
    /*
    * This function deletes the selected student from school.
    */        
        delete courses[currentCourseIndex];
        numCourses--;
        for (int i = currentCourseIndex; i < numCourses; i++) {
            courses[i] = courses[i+1];
        }
    }

    void SchoolManagerSystem::addSelectedStudentToCourse() { //to define addSlectedStudentToCourse
    /*
    * This function firstly prints the courses which are not taken by selected student 
    *  then it takes user option for course and it adds the selected student to that course.
    */   
        int choice;
        cout<<"0 - up"<<endl;
        for (int i = 0; i < numCourses; i++) {
            if (courses[i]->hasRegistered(students[currentStudentIndex]) == 0) { //to check all the courses which are not taken by student with using hasRegistered function.
                cout<<i+1<<" "<<courses[i]->getCode()<<" "<<courses[i]->getName()<<endl; // to print not registered courses.
            }
        }
        cin>>choice; //to get user input for course selection.
        courses[choice-1]->addStudent(students[currentStudentIndex]); //to add student to course.
        students[currentStudentIndex]->addCourse(courses[choice]);
    }

    void SchoolManagerSystem::dropSelectedStudentFromCourse() { //to define dropSelectedStudentFromCourse function.
    /*
    * This function firstly prints the courses which are taken by selected student 
    *  then it takes user option for course and it drops the selected student to that course. 
    */
        int choice;
        cout<<"0 - up"<<endl;
        for (int i = 0; i < numCourses; i++) {
            if (courses[i]->hasRegistered(students[currentStudentIndex]) == 1) { //to check all the courses which are taken by student with using hasRegistered function.
                cout<<i+1<<" "<<courses[i]->getCode()<<" "<<courses[i]->getName()<<endl; // to print registered courses.
            }
        }    
        cin>>choice; //to get user input for course selection.
        courses[choice-1]->removeStudent(students[currentStudentIndex]); //to remove (drop) student from course.
        students[currentStudentIndex]->removeCourse(courses[choice]);
    }

    void SchoolManagerSystem::listStudentsRegisteredToSelectedCourse() { //to define listStudentsRegisteredToSelectedCourse function.
    /*
    * This function lists the students of selected course.
    */
        Course* course = courses[currentCourseIndex]; //to create a course object and assign selected course.
        cout << "Students registered to course " << course->getName() << ":" << endl;
        students = course->getStudents();
        for(int i=0;i<courses[currentCourseIndex]->getNumStudents();i++){ //to create for loop for print out the students one by one.
            cout<<students[i]->getName()<<" "<<students[i]->getID()<< endl;
        }
    }

    void SchoolManagerSystem::listAllStudents() { //to define listAllStudents function.
        cout << "List of all students:" << endl;
        for (int i = 0; i < numStudents; i++) { //to create a for loop for print out the all students of school one by one.
            cout << students[i]->getName() << "  " << students[i]->getID() <<endl;
        }
    }

    void SchoolManagerSystem::listAllCourses() { //to define listAllStudents function.
        cout << "List of all courses:" << endl;
        for (int i = 0; i < numCourses; i++) { //to create a for loop for print out the all courses of school one by one.
            cout << courses[i]->getCode() << "  " << courses[i]->getName() << endl;
        }
    }

}