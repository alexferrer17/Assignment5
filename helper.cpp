#include <string>
#include <iostream>
#include <fstream>
#include "helper.h"

using namespace std;

void helper::Simulation()
{
  cout << "Hello welcome to Chapma's faculty/students database" << '\n';
  string choice = "";
  while (choice != "14")
  {
    cout << "Enter one of the options:" << '\n';
    cout << "(1) Print all the students and their information(sorted by ascending id#) " << '\n';
    cout << "(2) Print all faculty and their information(sorted by ascending id#)" << '\n';
    cout << "(3) Find and display student information given the students id" << '\n';
    cout << "(4) Find and display faculty information given the faculty id " << '\n';
    cout << "(5) Given a student’s id, print the name and info of their faculty advisor " << '\n';
    cout << "(6) Given a faculty id, print ALL the names and info of his/her advisees." << '\n';
    cout << "(7) Add a new student" << '\n';
    cout << "(8) Delete a student given the id" << '\n';
    cout << "(9) Add a new faculty member" << '\n';
    cout << "(10) Delete a faculty member given the id" << '\n';
    cout << "(11) Change the student's advisors given the student id and the new faculty id" << '\n';
    cout << "(12) Remove an advisee from a faculty member given the ids" << '\n';
    cout << "(13) RollBack" << '\n';
    cout << "(14) Exit" << '\n';
    getline(cin,choice);
    int numberChosen = stoi(choice);

    if (numberChosen < 15)
    {

    switch(numberChosen)
    {
    case 1 :
    printStudents();
    break;

    case 2:
    printFaculties();
    break;

    case 3:
    {
      cout << "Enter the id of the searched student:" << '\n';
      string s = "";
      getline(cin,s);
      int sID = stoi(s);
      if(student.contains(sID))
      {
        printStudents(sID);
      }
      break;
    }
    case 4:
    { //prints faculty with given id
      cout << "Enter the id of the search faculty: " << '\n';
      string s = "";
      getline(cin,s);
      int sID = stoi(s);
      if(faculty.contains(sID))
      {
        printFaculties(sID);
      }

    break;
    }
    case 5: //prints faculty info given a student id
    {
      cout << "Enter the students ID number: " << '\n';\
      string s = "";
      getline(cin,s);
      int sID = stoi(s);
      if( student.contains(sID))
      {
        printStudentsAdvisors(sID);
      }

    break;
    }
    case 6:
    {
      std::cout << "Enter the Faculty ID:" << '\n';
      string s = "";
      getline(cin, s);
      int fID = stoi(s);
      if (faculty.contains(fID))
      {
        printStudentsAdvisors(fID);
      }

    break;
    }
    case 7:
    { //enter a new faculty
      cout << "What is the student name?" << endl;
      string name = "";
      getline(cin,name);
      int id = rand() % 100;
      if (student.contains(id))
      {
        id = rand() % 100;
      }
      cout << "Enter Student's level: " << '\n';
      string level = "";
      getline(cin,level);
      cout << "Enter students GPA: " << '\n';
      string gpa = "";
      getline(cin, gpa);
      float Gpa = stof(gpa);
      cout << "Enter students major: " << '\n';
      string major = "";
      getline(cin, major);
      cout << "Enter the faculty advisor ID" << '\n';
      string fID = "";
      getline(cin, fID);
      int fid = stoi(fID);
      addStudent(Student(name,id,major,Gpa,fid));



    break;
    }
    case 8:
    {
      std::cout << "Enter Student's id: " << '\n';
      string stid = "";
      getline(cin,stid);
      int sid = stoi(stid);
      removeStudent(sid);

    }
    break;

    case 9:
    {// enter a new faculty
      cout << "What is the faculty name?" << endl;
      string name = "";
      getline(cin,name);
      int id = rand() % 100;
      if (student.contains(id))
      {
        id = rand() % 100;
      }
      cout << "Enter Faculty's level: " << '\n';
      string level = "";
      getline(cin,level);
      cout << "Enter Faculty's department: " << '\n';
      string gpa = "";

      //addStudent(Student(name,id,major,Gpa,fid));


    break;
    }
    case 10:
    //remove faculty
    {
      std::cout << "Enter Faculty's id: " << '\n';
      string fcid = "";
      getline(cin,fcid);
      int fid = stoi(fcid);
      removeStudent(fid);

    break;
    }
    case 11:
    {

    break;
    }
    case 12:
    //
    break;

    case 13:
    {//undo
    break;
    }
    case 14:
    //EXIT
    break;
    }
  }
  else
  {
    cout << "Enter a valid number" << '\n';
  }
}
}
void helper::printStudents()
{
  student.printTree();
}

void helper::printFaculties()
{
  faculty.printTree();
}


void helper::printStudents(int id)
{
  cout << student.find(id)  << '\n';
}

void helper::printFaculties(int id)
{
  cout << faculty.find(id) << endl;
}

void helper::printStudentsAdvisors(int fid)
{

}

void helper::printFacultiesStudents(int fac)
{

}

void helper::addStudent(Student std)
{

}
void helper::addFaculty(Faculty fac)
{

}
void helper::removeFaculty(int id)
{

}
void helper::removeStudent(int id)
{

}
