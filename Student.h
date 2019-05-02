#include <string>
using namespace std;

class Student{

public:
  Student()
  {
  //
  }
  Student(int k)
  {
    studentID = k;
  }
  Student(string name, int k, string m, double gpa, int facultyid)
  {

      left = NULL;
      right = NULL;
      Name = name;
      studentID = k;
      major = m;
      GPA = gpa;
      facultyID = facultyid;
  }

  ~Student(){};
  Student *left;
  Student *right;
  Student *data;
  int getID();
  double getGPA();
  string getStudentName();
  string getMajor();
  int getFacultyID();
  void setFacultyId();
  int studentID; //original

private:
  string Name;
  string major;
  double GPA;
  int facultyID;

};
