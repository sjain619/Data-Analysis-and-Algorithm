#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
class BinNode;
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void inOrder() const;
  void preOrder() const;
  void nodeCount() const;
  void deleteNode(int item);

 private:
  void inOrder(const BinNode * ptr) const;
  void preOrder(const BinNode * ptr) const;
  int nodeCount(const BinNode * ptr) const;
  void deleteNode(BinNode * ptr,BinNode * parent,int item);
  void deleteChild(BinNode * ptr,BinNode * parent,int item);
//delete a node in tree 
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;
    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };

  BinNode * myRoot; 

}; // end of class declaration
// void inOrder(BST::BinNode *ptr);
#endif
