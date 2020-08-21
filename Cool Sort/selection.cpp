#include<iostream>
using namespace std;

void SelectionSorta(int Arr[], int size){		// part A this is an implemented logic of selection sort
        int min,j;
        for(int i=0;i<size -1;i++){
                min=i;
                for(j=i+1;j<size;j++){
                        if(Arr[j]<Arr[min])
                                min = j;
                }
                int temp=Arr[min];
                Arr[min]=Arr[i];
                Arr[i]=temp;
        }
	cout <<"PART A"<<endl;
        for(int i=0;i<size;i++){
                cout<<Arr[i]<<endl;
        }
}

void SelectionSortb(int Arr[],int Size,int k){		//Part B this is an implemented logic of selection sort from 1 to k
        int i,j,min;
        for(i=0;i<k;i++){
                min=i;
                for(j=i+1;j<Size;j++){
                        if(Arr[j]<Arr[min])
                                min=j;
                }
                int temp=Arr[min];
                Arr[min]=Arr[i];
                Arr[i]=temp;
        }
	cout<<"PART B"<<endl;
                for(i=0;i<k;i++){
                        cout<<Arr[i]<<endl;
                }
}

int SelectionSortc(int Arr[],int Size,int k){		//Part c finding the median of first k elements to find the median of all n replace k by n in this function 
	int i,j,min; double median;
	for(i=0;i<k;i++){
		min=i;
		for(j=i+1;j<Size;j++){
			if(Arr[j]<Arr[min])
				min=j;
		}
		int temp=Arr[min];
		Arr[min]=Arr[i];
		Arr[i]=temp;
	}
	if(k%2==0){
		int m=k/2;
		median=(( Arr[m]+Arr[m-1])/2);
	}
	else{
		int m=k/2;
		median= Arr[m];
	}
	return median;

}
int main(){
	int size, k;
	cout << "Please Enter the size of the array" <<endl;
	cin >> size;
	cout << "enter values one by one " << endl;
	int Arr[size];
	for(int i=0;i<size;i++){
		cin>>Arr[i];
	}
	cout << "Please enter the value of k" <<endl;
	cin>>k;
	SelectionSorta(Arr,size);
	SelectionSortb(Arr,size,k);
	int median = SelectionSortc(Arr,size,k);
	cout <<"Median value is " << median <<endl;
	return 0;
}
