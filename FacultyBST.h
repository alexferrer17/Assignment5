#include "Faculty.h"
#include <string>
using namespace std;

class FacultyBST
{
public:
  FacultyBST();
   ~FacultyBST();
  void insert(int value);
  bool contains(int studentID); //AKA search
  bool deleteRec(int value);
  Faculty* getSuccesor(Faculty* d);
  bool deleteNode(Faculty* node);

  Faculty* GetMin();
  Faculty* GetMax();
  Faculty* find(int id);
  bool isEmpty();
  void printTree();
  void recPrint(Faculty* node);


private:
  Faculty* root;

};
