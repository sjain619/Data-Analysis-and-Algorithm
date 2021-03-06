#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}
void BST::preOrder() const{
	cout <<"preOrder: \n";
	preOrder(myRoot);
	cout<<"\n";
}
void BST::preOrder(const BinNode * ptr) const{
	if(ptr!=0){
		cout<<" "<< ptr->data;
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
	else
		return;
}
void BST::inOrder() const{
	cout<<"Problem 1 ";
	cout<<"inOrder: \n";
	inOrder(myRoot);
	cout<<"\n";
}
void BST::inOrder(const BinNode * ptr) const{
	if(ptr!=0){
		inOrder(ptr->left);
		cout<<" "<<ptr->data;
		inOrder(ptr->right);
	}
	else 
		return;
} 
void BST::nodeCount() const{
	int i=nodeCount(myRoot)-1;
	cout<<"\nCount of nodes is: "<<i<<"\n";
	cout<<"Problem 2"<<"\n";
}
int BST::nodeCount(const BinNode * ptr) const{
	int n=1;
	if(ptr!=0){
		n=nodeCount(ptr->left)+nodeCount(ptr->right);
	}else
		return n;
}
void BST::deleteChild(BinNode * ptr,BinNode * parent,int item){
	if((ptr->left ==0)&&(ptr->right==0)){
		if(parent->right == ptr){
			parent->right =0;
		}
		else{
			parent->left =0;
		}
		free(ptr);
	}
	else if(ptr->left == 0){
		BinNode * next=ptr->right;
		if(parent->right==ptr){
			parent->right=next;
		}
		else{
			parent->left=next;
		}
		free(ptr);
	}
	else if(ptr->right ==0){
		BinNode * next=ptr->left;
		if(parent->left==ptr){
			parent->left=next;
		}
		else{
			parent->right=next;
		}
		free(ptr);
	}
	else{
		BinNode * temp= ptr;
		while(temp->left!=0){
			parent = temp;
			temp=temp->left;
		}
		ptr->data=temp->data;
		if(parent->right == ptr){
			parent->right=0;
		}else{
			parent->left=0;
		}
		free(temp);
	}

}
void BST::deleteNode(BinNode * ptr,BinNode * parent,int item){
	if(item > ptr->data){
		deleteNode(ptr->right,ptr,item);
	}
	else if(item<ptr->data){
		deleteNode(ptr->left,ptr,item);
	}
	else if(ptr==0){
		cout<<"not found";
	}
	else{
		deleteChild(ptr,parent,item);
	}
}
void BST::deleteNode(int item){
	deleteNode(myRoot,0,item);
}

