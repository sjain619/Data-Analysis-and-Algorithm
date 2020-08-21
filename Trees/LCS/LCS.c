#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int x,int y){
	int s=x>y?x:y;
	return s;
}

int main(){
	int a,b;	
	printf("Enter the size of A and B\n");
	scanf("%d\n",&a);
	scanf("%d",&b);
	printf("Enter the value of the string\n ");
	char str1[a];
	char str2[b];
	int s=a>b?b:a;
	char *LCS=malloc(sizeof(char)*s);
	int count=0;
	scanf("%s",str1);
	printf("Enter the other string \n");
	scanf("%s",str2);
	//printf("%s / %s",str1, str2);
	a++;
	b++;

	/*Defination*/
	int matrix[a][b];
	
	/*initialization*/

	for(int j=0;j<a;j++){
		matrix[j][0]=0;
	}
	for(int j=0;j<b;j++){
		matrix[0][j]=0;
		}
	int k=0;
	for(int i=1;i<a&& k<s;i++){
		for(int j=1;j<b;j++){
			if(str1[i-1]==str2[j-1]){
				matrix[i][j]=matrix[i-1][j-1]+1;
				if(count<matrix[i][j]){
						LCS[k]=str1[i-1];
						LCS[k+1]='\0';
						k++;
						count=matrix[i][j];
					//	break;
					}
				}

			else{
				matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
			}
		}
	}
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("Length of LCS:%d \n",matrix[a-1][b-1]);
	printf("LCS: %s \n",LCS);
}
