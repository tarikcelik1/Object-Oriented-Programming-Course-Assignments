#include <iostream>
#include "SchoolManagerSystem.h"

using namespace std;
using namespace PA4;

int main() {
    SchoolManagerSystem school; //to create a schoolManagerSystem object.
    int mainchoice;
    string name,firstname,lastname;  //to define some variables for user inputs.
    string course_name,code;
    int id;
    cout << "Main_menu\n";
    do{ //to create main menu.
            cout << "0 exit\n"
            << "1 student\n"
            << "2 course\n"
            << "3 list_all_students\n"
            << "4 list_all_courses\n";

            
        cin>>mainchoice; //to get user input for main menu option.
        switch (mainchoice) //to create switch-case for main menu.
        {
        case 0: // Exit
        break;
        case 1: //this case for create student menu.
            int student_menu_choice;
            do{ 

                    cout << "0 up\n"
                        << "1 add_student\n"
                        << "2 select_student\n";

                    cin >> student_menu_choice; //to get user input for student menu option.
                    switch (student_menu_choice) //to create switch-case for student menu.
                    {
                    case 0: // Up menu.
                    break;
                    case 1: //this case for add student option of student menu.
                                cin >>firstname>>lastname; //to get user input for student name and id.
                                do{
                                    cin.clear();
                                    cin.ignore();
                                    cin >> id;
                                }while(cin.fail() == 1);
                                name = firstname+" "+lastname;
                                school.addStudent(name, id); //to call addstudent function.
                        break;
                    case 2: //this case for select student option of student menu.
                        int student_menu_choice2;
                                cin >>firstname>>lastname; //to get user input for student name and id.
                                do{
                                    cin.clear();
                                    cin.ignore();
                                    cin >> id;
                                }while(cin.fail() == 1);
                                name = firstname+" "+lastname;
                        if(school.selectStudent(name,id) == 1){ //to chechk selected student is exists or not.
                                do{
                                    cout << "0 up\n"
                                        << "1 delete_student\n"
                                        << "3 add_selected_student_to_a_course\n"
                                        << "4 drop_selected_student_from_a_course\n";
                                        cin>>student_menu_choice2;
                                        switch (student_menu_choice2) //to cerate switch-case for sub-menu of student menu(select student option).
                                        {
                                        case 0: //Up menu.
                                            break;
                                        case 1: //this case for delete selected student from school.
                                            school.deleteStudent(); //to call deleteStudent function.
                                            student_menu_choice2 = 0; //to up to the student menu.
                                            break;
                                        case 3: //this case fro add selected student to a course which is not taken before.
                                            school.addSelectedStudentToCourse(); //to call addSelectedStudentToCourse function.
                                            break;
                                        case 4: //this case for drop selected student from a course which is taken before.
                                            school.dropSelectedStudentFromCourse(); //to call dropSelectedStudentFromCourse function.
                                            break;
                                        } 
                                }while(student_menu_choice2 != 0);
                        }                       
                        break;
                        
                    }
            }while(student_menu_choice != 0);
            break;

            case 2: //course menu
            int course_menu_choice;
                do{
                    cout << "0 up\n"
                         << "1 add_course\n"
                         << "2 select_course\n";
                    cin>>course_menu_choice; //to get user input for course menu option.
                    switch (course_menu_choice) //to create switch-case for create course menu.
                    {
                    case 0: //upp
                        break;
                    case 1: //this case for add course.
                            cin>>code; //to get user input for course code.
                            getline(cin,course_name); //to get user input for course name.
                            school.addCourse(course_name,code); //to call addCourse function.
                        break;
                    case 2: //this case for select course.
                            int course_menu_choice2;
                            cin>>code; //to get user input for course code.
                            getline(cin,name); //to get user input for course name.
                            if(school.selectCourse(code) == 1){ //to check selected course exist or not.
                                do{
                                    cout << "0 up\n"
                                        << "1 delete_course\n"
                                        << "2 list_students_registered_to_selected_course\n";
                                        cin>>course_menu_choice2; //to get user input for sub-menu of course menu (select course option menu).                               
                                    switch(course_menu_choice2){ //to createe switch-case for select course menu.
                                        case 0: // Up menu.
                                            break;
                                        case 1: //this case for delete course.
                                                school.deleteCourse(); //to call deleteCoure function.
                                                course_menu_choice2 = 0; //to up to the course menu.
                                            break;
                                        case 2: //this case for listStudentsRegisteredToSelectedCourse.
                                                school.listStudentsRegisteredToSelectedCourse(); //to call listStudentsRegisteredToSelectedCourse.
                                            break;
                                    }
                                }while(course_menu_choice2 != 0);

                            }
                        break;
                    }                        
                }while(course_menu_choice != 0);
            break;
        case 3: //this case for list all students of school.
                school.listAllStudents();
            break;
        case 4: //this case for list all courses of school.
                school.listAllCourses();
            break; 
        
        default:
            break;
        }
   

    }while(mainchoice != 0);
return 0;
}



