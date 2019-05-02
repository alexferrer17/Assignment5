#include <string>
using namespace std;

class Faculty {

public:
  Faculty *left;
  Faculty *right;
  int facultyID;

  Faculty()
  {
    left = NULL;
    right = NULL;
  }
  Faculty(int k)
  {
    facultyID = k;
  }
  Faculty(string n, int fID, string lvl, string dptm)
  {
    name = n;
    facultyID = fID;
    level = lvl;
    department = dptm;
  }
   ~Faculty()
   {
   }
   int getStudCount();
   int getFacultyID();
   void addStudentF(int student);
   void removeStudentF(int student);
   //int* listStudents();

private:
  string name;
  string level; //(lecturer, assitant prof, associate,etc)
  string department;
  int *students;
  int count;

};
