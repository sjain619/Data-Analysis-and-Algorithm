#include<iostream>
using namespace std;

int SearchIndex(int Arr[],int p,int r){  // this step is similar to the divide step of merge sort
	int q;
	if(p<r){
		q=(p+r)/2;		//divide the array in two parts
		if(Arr[q]==q+1){
			return q+1;
		}
	else{
		if(Arr[q]>q+1){			//condition checks if the array is bigger of smaller
			SearchIndex(Arr,p,q-1);	//conquer by passing values
		}
		else{
			SearchIndex(Arr,q+1,r);
		}
		return -1;
	}
}
}

int main()
{
	int size,p=0;
	cout<<"Please enter size of the array"<<endl;
	cin>>size;
	int Arr[size];
	cout << "Please enter the elements 1 at a time"<<endl;
	for(int i=0;i<size;i++){
		cin>>Arr[i];
	}
	int ind = SearchIndex(Arr,p,size-1);
	cout<< "OUTPUT (-1 means not found)";
	cout<< ind;
	cout<< endl;
	return 0;
}
