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
int BST::height(BinNode * N){
	if(N==0)
		return 0;
	return N->height;
}
int max(int a,int b){
	return (a>b)?a:b;
}
BST::BinNode *BST::rightRotate(BinNode * y){
	BinNode * x=y->left;
	BinNode * T1=x->right;
	x->right=y;
	y->left=T1;
	y->height=max(height(y->left),height(y->right)+1);
	y->height=max(height(x->left),height(y->right)+1);
	return x;
}
BST::BinNode * BST::leftRotate(BinNode * ptr){
	BinNode * x=ptr->left;
	BinNode * T1=x->right;
	ptr->left=x;
	x->right=T1;
	x->height=max(height(x->left),height(x->right))+1;
	ptr->height = max(height(ptr->left),height(ptr->right))+1;
	return ptr;
}
int BST::getBalance(BinNode * ptr){
	if(ptr == 0)
		return -1;
	return height(ptr->left)-height(ptr->right);
}
BST::BinNode * BST::insert(const int & item)
{
   int f=0;
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
      if (parent == 0){               // empty tree
         myRoot = locptr;
	 f=1;
      }
      else if (item < parent->data ){  // insert to left of parent
         parent->left = locptr;
	 f=1;
      }
      else
	     parent->right=locptr;
      if(f==1){
      	locptr->height = 1+ max(height(locptr->left),height(locptr->right));
      	int balance = getBalance(locptr);
	if(balance>1&& item>locptr->right->data){
		return rightRotate(locptr);
      }
	else if(balance <-1 && item> locptr->right->data){
		return leftRotate(locptr);
	}
	else if(balance>1 && item>locptr->right->data){
		locptr->left=leftRotate(locptr->left);
		return rightRotate(locptr);
	}
	else if(balance<-1 && item<locptr->left->data){
		locptr->left =rightRotate(locptr->left);
		return leftRotate(myRoot);
	}
	return myRoot;

   }
   else
      cout << "Item already in the tree\n";

   }
}
void BST::insert1(const int & item){
	insert(item);
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
}
int BST::nodeCount(const BinNode * ptr) const{
	int n=1;
	if(ptr!=0){
		n=nodeCount(ptr->left)+nodeCount(ptr->right);
	}else
		return n;
}
BST::BinNode * BST::deleteChild(BinNode * ptr,BinNode * parent,int item){
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
		BinNode * newParent= 0;
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
		parent->height=1+max(height(parent->left),height(parent->right));
		int balance =getBalance(parent);
		if(balance>1 && getBalance(parent->left)<=0)
			return rightRotate(parent);
		if(balance >1 && getBalance(parent->left)<0){
				parent->left=leftRotate(parent->left);
				return rightRotate(parent);
				}
		if(balance<-1 && getBalance(parent->right)<=0)
			return leftRotate(parent);
		if(balance<-1 && getBalance(parent->right)){
			parent->right=rightRotate(parent->right);
			return leftRotate(parent);
		}
		return parent;
	}

}
void BST::deleteNode(BinNode * ptr,BinNode * parent,int item){
	if(item > ptr->data){
		deleteNode(ptr->right,ptr,item);
	}
	else if(item<ptr->data){
		deleteNode(ptr->left,ptr,item);
	}
	else{
		deleteChild(ptr,parent,item);
	}
}
void BST::deleteNode(int item){
	deleteNode(myRoot,0,item);
}
//referred geeksforgeeks.org

