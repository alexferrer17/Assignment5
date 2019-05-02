#include "StudentBST.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

StudentBST::StudentBST()
{ //constructor
  root = NULL;
}

StudentBST::~StudentBST()
{
  deleteNode(root);
}

void StudentBST::printTree()
{
  recPrint(root);
}

void StudentBST::recPrint(Student* node) {
  if(node == NULL)
  {
    return;
  }

  recPrint(node -> left);
  cout << node-> studentID << endl;
  recPrint(node -> right);
}

bool StudentBST::isEmpty() {
  return (root == NULL);
}

void StudentBST::insert(int value) { //have to check: parents, root, current!
  //check if value exists, if not continue
  Student* node = new Student(value); //node is set to valueNode

  if(root = NULL)
  {
    root = node;
  }
  else //not an empty tree
  {
    Student *current = root;
    Student *parent; //empty node

    while(true) // want to look until you find the place
    {
      parent = current;
      if ( value < current -> studentID) //go left
      {
        current = current -> left; //keep going left
        if(current = NULL)//found location for our node
        {
          parent -> left = node;
          break;
        }
        //else keep going
      }
      else //go right
      {
        current = current -> right;
        if (current = NULL)
        {
          parent -> right = node;
          break;
        }
      }

    }
  }
}
bool StudentBST::contains(int value) {
  if (isEmpty())
  {
    return false;
  }
  else { //not an empty tree very similar to insert

    Student* current = root;

    while(current -> studentID != value)
    {
      if(value < current -> studentID) //goes left
      {
        current = current -> left;
      }
      else
      {
        current = current -> right;
      }
      if (current = NULL)
      {
        return false;
      }

    }

  }
  return true;
}

// delete method you have to check if there is one children or two children

bool StudentBST::deleteRec(int value) {
  if (isEmpty())
  {
    return false;
  }
    //check if studentID value exists before continuing to delete
    Student *current = root;
    Student *parent = root;
    bool isLeft = true;

    while(current-> studentID != value) //search for it
    {
      parent = current;

      if(value < current -> studentID)
      {
        isLeft = true;
        current = current -> left;
      }
      else
      {
        isLeft = false;
        current = current -> right;
      }
      if ( current == NULL)
      {
        return false;
      }
    }
    //at this p oint we found our node
    //now lets check our cases
    if(current->left == NULL && current->right == NULL) //no children, leaf node
    {
      if(current == root)
      {
        root = NULL;
      }
      else if(isLeft) //if is left
      {
        parent -> left = NULL;
      }
      else //if is right
      {
        parent -> right = NULL;
      }
    }
    else if (current -> right == NULL) //check if the node has only one child
    {
      if (current == root) //we always have to check if we are deleting the root
      {
        root = current -> left;
      }
      else if (isLeft)
      {
        parent -> left = current -> left;
      }
      else
      {
        parent -> right = current -> left;
      }

    }
    else if (current -> left == NULL) //check if the node has only one child
    {
      if (current == root)
      {
        current = NULL;
      }
      else if (isLeft)
      {
        parent -> left = current -> right;
      }
      else
      {
        parent -> right = current -> right;
      }
    }
    else //the node has two children
    {
      //find the succesor of the node to be deleted in this case current
      Student *succesor = getSuccesor(current);

      //have to check some cases
      if(current = root)
      {
        root = succesor;
      }
      else if(isLeft)
      {
        parent -> left = succesor;
      }
      else
      {
        parent -> right = succesor;
      }

      succesor -> left = current-> left;
    }
    return true;
}

  bool StudentBST::deleteNode(Student *node)
  {
    deleteRec(node->studentID);
  }

  Student* StudentBST::getSuccesor(Student *d) // d is the node to be deleted
    {
        Student *sp = d; //succesor parent
        Student *succesor = d; //
        Student *current = d-> right; // current

        while(current != NULL) //get every pointer in position
        {
          sp = succesor;
          succesor = current;
          current = current -> left;
        }

        if (succesor != d-> right)
        {
          sp-> left = succesor -> right;
          succesor -> right = d -> right;
        }
    }

    Student* StudentBST::find(int id)
    {
      if(contains(id))
      {
        Student* current = root;
        while(current != NULL)
        {

            if (current->studentID == id)
            {
              return current;
            }
            else if (current->studentID > id)
            {
              current = current->left;
            }
            else
            {
              current = current->right;
            }
        }
      }

    }
