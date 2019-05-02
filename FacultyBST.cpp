#include "FacultyBST.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

FacultyBST::FacultyBST() { //constructor
  root = NULL;
}

FacultyBST::~FacultyBST()
{
  deleteNode(root);
}

void FacultyBST::printTree()
{
  recPrint(root);
}

void FacultyBST::recPrint(Faculty* node) {
  if(node == NULL)
  {
    return;
  }

  recPrint(node -> left);
  cout << node-> facultyID << endl;
  recPrint(node -> right);
}

bool FacultyBST::isEmpty() {
  return (root == NULL);
}

void FacultyBST::insert(int value) { //have to check: parents, root, current!
  //check if value exists, if not continue
  Faculty* node = new Faculty(value); //node is set to valueNode

  if(root = NULL)
  {
    root = node;
  }
  else //not an empty tree
  {
    Faculty *current = root;
    Faculty *parent; //empty node

    while(true) // want to look until you find the place
    {
      parent = current;
      if ( value < current -> facultyID) //go left
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
bool FacultyBST::contains(int value) {
  if (isEmpty())
  {
    return false;
  }
  else { //not an empty tree very similar to insert

    Faculty* current = root;

    while(current -> facultyID != value)
    {
      if(value < current -> facultyID) //goes left
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

bool FacultyBST::deleteRec(int value) {
  if (isEmpty())
  {
    return false;
  }
    //check if facultyID value exists before continuing to delete
    Faculty *current = root;
    Faculty *parent = root;
    bool isLeft = true;

    while(current-> facultyID != value) //search for it
    {
      parent = current;

      if(value < current -> facultyID)
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
    //at this point we found our node
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
      Faculty *succesor = getSuccesor(current);

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

  bool FacultyBST::deleteNode(Faculty *node)
  {
    deleteRec(node->facultyID);
  }

  Faculty* FacultyBST::getSuccesor(Faculty *d) // d is the node to be deleted
    {
        Faculty *sp = d; //succesor parent
        Faculty *succesor = d; //
        Faculty *current = d-> right; // current

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

    Faculty* FacultyBST::find(int id)
    {
      if(contains(id))
      {
        Faculty* current = root;
        while(current != NULL)
        {
          if (current->facultyID == id)
          {
            return current;
          }
          else if (current->facultyID > id)
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
