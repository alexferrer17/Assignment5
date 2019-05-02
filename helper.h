#include <string>
#include <iostream>
#include <fstream>
#include "StudentBST.h"
#include "FacultyBST.h"
class helper
{
public:

  helper()
  {
    student = StudentBST();
    faculty = FacultyBST();

  }
  ~helper()
  {

  }

  void Simulation();
  void printStudents();
  void printStudents(int id);
  void printFaculties();
  void printFaculties(int id);
  void printStudentsAdvisors(int sid);
  void printFacultiesStudents(int fid);
  void addStudent(Student std);
  void addFaculty(Faculty fac);
  void removeStudent(int id);
  void removeFaculty(int id);


private:
  StudentBST student;
  FacultyBST faculty;
};
