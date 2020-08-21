#include<iostream>
using namespace std;
void CoolSort(int Arr[], int size, int H[], int size1) {
	for(int k=0;k<size1;k++){		//getting the values of H from input
		for(int j=1;j<size;j=j+H[k]){	//performing insertion sort
			int key=Arr[j];		//insert in sorted sequence
			int i=j-H[k];
			while(i>=0 && Arr[i]>key){
					Arr[i+H[k]]=Arr[i];
					i=i-H[k];
			}
			Arr[i+H[k]] = key;
		}
	}
	cout << "OUTPUT"<<endl;
	for(int i=0;i<size;i++){ 		//printing
		cout << Arr[i] <<endl;
	}
}


int main(){
	int size,size1;
	cout << "Please enter the size of the input. " << endl;
	cin >>size;
	int A[size];
	cout << " Please enter the values. "<<endl;
       	for(int i=0;i<size;i++){
		cin >> 	A[i];
	}
	cout << "Please enter the size H. " <<endl;
	cin >> size1;
	int H[size1];
	cout << " Please enter the values of H. " << size1<<endl;
	for(int i=0;i<size1;i++){
		cin >> H[i];
	}
	CoolSort(A,size,H,size1);
}
	
