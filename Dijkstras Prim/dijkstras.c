#include <stdio.h>
#include <stdlib.h>
#define MAX -9999

int costGraph[6][6];
int finalValues[6];
int finalNodes[6];
int visited[6];
int unvisited[6];
int stepNO = 0 ;
int startNode = 0 ;
int insertptr=0;
int i=0;

void initialize(){
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++) {
				if(i==j) {
					costGraph[i][j] = 0;
				}
				else {
					costGraph[i][j] = 100;
				}
			}
		}
	}

void printtable(){
    int i;
    stepNO++;
    printf("%c",visited[i]);
    printf("\t\t");
    for(i=0;i<6;i++){
        printf("%d, %d \t", finalValues[i],finalNodes[i]);
    }
    printf("\n");
}

void addEdges(int from,int to, int cost){
    if(from!=to){
            costGraph[from][to]=cost;
            costGraph[to][from]=cost;
    }
    return;
}
void findMinimum() {
    int min = MAX;
    int minNode = 0;
    for(int i = 0; i<6;i++) {
        int value = MAX;
        if(!visited[i]) {
            value = finalValues[i];
            if(value < min) {
                min = value;
                minNode = i;
            }
        }
    }
    visited[i]=minNode;
    for(int i=0;i<(sizeof(unvisited)/sizeof(int));i++) {
        int value = unvisited[i];
        if(value == minNode) {
            unvisited[i]=MAX;
            i--;
        }
    }
}
void djikstra() {
    while((sizeof(unvisited)/sizeof(int))>0 ) {
        findMinimum();
        int length = (sizeof(unvisited)/sizeof(int));
        int index = (sizeof(visited)/sizeof(int));
        int currentValue = finalValues[index];
        for(int i = 0;i<length;i++) {
            int ind = unvisited[i];
            int firstValue = finalValues[ind];
            int secondValue = costGraph[index][ind];
            if(firstValue > (currentValue+secondValue)) {
                finalValues[ind] = currentValue+secondValue;
                finalNodes[ind] = index;
            }
        }
    printtable();
    }
    
}
void intdjik(int startNode) {
                visited[i]=startNode;
                for(int i=0;i<6;i++) {
                    if(i != startNode) {
                                unvisited[i]=i;
                    }
                finalValues[i] = costGraph[visited[0]][i];
                            finalNodes[i] = visited[0];
                    }
                        printtable();
                        djikstra();
}
char * intToChar(int index) {
                                        
            switch(index) {
                    case 0 : return "U";
                    case 1 : return "V";
                    case 2: return "W";
                    case 3 : return "X";
                    case 4: return "Y";
                    case 5: return "Z";
                    default: return "Invalid";
        }
    }
int main(){
        initialize();
        addEdges(1,2,2);
        addEdges(1,3,1);
        addEdges(2,3,2);
        addEdges(2, 4, 3);
        addEdges(3, 5, 1);
        addEdges(4, 5, 1);
        addEdges(4, 6, 5);
        addEdges(6, 5, 2);
        addEdges(3, 4, 3);
        intdjik(startNode);
                                        
	return 0;
}
