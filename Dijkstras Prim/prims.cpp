#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <functional>
#include <limits.h>
#include "prims.h"
using namespace std;

void printMST(int adj_matrix[30][30], int vertice)
{
    printf("Edge   Weight\n");
    for ( int i = 1; i < vertice; i++ )
        printf("%d - %d    %d \n", vertex[i].parent, i, adj_matrix[i][vertex[i].parent]);
}

void Prim_algorithm(){
    
    int vertices;
    cout << endl << "Enter the number of vertices in the graph:";
    cin >> vertices;
    int adj_matrix[vertices][vertices];
    char mat_label[27];
    cout << endl << "Enter the vertices" << vertices;    //Accepting each vertex label
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            adj_matrix[i][j]=0;
        }
    }
    for ( int i = 0; i < vertices; i++ ){
        cin >> mat_label[i];
    }
    
    for ( int i = 0; i < vertices; i++ ){
        for ( int j = 0; j < vertices; j++ ){
            adj_matrix[i][j] = INT_MAX;
        }
    }
    
    for ( int i = 0; i < vertices; i++ ){
        for ( int j = 0; j < vertices; j++ ){
            if(adj_matrix[j][i] == INT_MAX){
                cout << endl << "Enter the weight of the edge between vertex " << mat_label[i] << " and vertex " << mat_label[j] << "(or 0 if no edge exists):";
                cin >> adj_matrix[i][j];
                adj_matrix[j][i] = adj_matrix[i][j];
            }
        }
    }
    
    
    for ( int i = 0; i < vertices; i++ )
    {
        vertex[i].key = INT_MAX;
        vertex[i].color = 0;
    }
    vertex[0].key = 0;
    vertex[0].parent = -1;
    vector<int> p_queue;
    for ( int i = 0; i < vertices; i++ )
        p_queue.push_back(vertex[i].key);
    std::sort(p_queue.begin(), p_queue.end());
    
    int u, x, index;
    for(int j = 0; j < vertices - 1; j++ )
        //while(!p_queue.empty())
    {
        u = p_queue.front();
        p_queue.erase(p_queue.begin());
        x = 0;
        while ( x < vertices )
        {
            if ( vertex[x].key == u )
            {
                index = x;
                break;
            }
            else
                x++;
        }
        vertex[index].color = 1;
        for ( int i = 0; i < vertices; i++ )
        {
            if ( adj_matrix[u][i] && vertex[i].color == 0 && adj_matrix[u][i] < vertex[i].key )
            {
                vertex[i].key = adj_matrix[u][i];
                p_queue.pop_back();
                p_queue.push_back(vertex[i].key);
                std::sort(p_queue.begin(), p_queue.end());
                vertex[i].parent = u;
            }
        }
     
    }
    
    
    printf("\nOutput:\nEdge   Weight\n");
    for ( int i = 1; i < vertices; i++ )
        printf("%c - %c    %d \n", mat_label[vertex[i].parent], mat_label[i], adj_matrix[i][vertex[i].parent]);
    
}
int main(){
    Prim_algorithm();
    return 0;
}
