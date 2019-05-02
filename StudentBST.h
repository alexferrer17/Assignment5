#include "Student.h"
using namespace std;

  class StudentBST
  {
  public:
    StudentBST();
    ~StudentBST();
    void insert(int value);
    bool contains(int studentID); //AKA search
    bool deleteRec(int value);
    Student* getSuccesor(Student* d);
    bool deleteNode(Student* node);

    Student* GetMin();
    Student* GetMax();
    bool isEmpty();
    void printTree();
    void recPrint(Student* node);
    Student* find(int id);

  private:
    Student* root;

  };
