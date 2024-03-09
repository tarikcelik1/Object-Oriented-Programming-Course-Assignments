#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include <string>
#include "Course.h"
#include "Student.h"

using namespace std;

namespace PA4 {
    class SchoolManagerSystem {
    public:
        SchoolManagerSystem(); //to define default constructor of SchoolManagerSystem calss.
        ~SchoolManagerSystem(); //to define destructor of SchoolManagerSystem class.
        
        void addStudent(const string& name, int id); //to define addStudent function.
        int selectStudent(const string& name, int id); //to define select student function.
        void deleteStudent(); //to define delete student function.
        void addSelectedStudentToCourse(); //to define addSlectedStudentToCourse
        void dropSelectedStudentFromCourse(); //to define dropSelectedStudentFromCourse function.
        void addCourse(const string& name, const string& code);//to define addCourse function.
        int selectCourse(const string& code); //to define select course function.
        void deleteCourse(); //to define delete course function.
        void listStudentsRegisteredToSelectedCourse(); //to define listStudentsRegisteredToSelectedCourse function.
        void listAllStudents(); //to define listAllStudents function.
        void listAllCourses(); //to define listAllCourses function.

    private:
        Student** students;
        int numStudents;
        Course** courses;  //to define private data members of SchoolManagementsystme class.
        int numCourses;
        int currentStudentIndex;
        int currentCourseIndex;

    };
}
#endif