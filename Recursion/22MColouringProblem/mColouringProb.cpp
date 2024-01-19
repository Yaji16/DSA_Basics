#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node,int colour[],bool graph[101][101], int n,int col){
    for(int k=0; k<n; k++){
        if(k!=node && graph[k][node]==1 && colour[k]==col) return false;
    }
    return true;
}

bool solve(int node,int colour[],int m,int n, bool graph[101][101]){
    if(node == n) return true;
    //trying every colour from 1 to m for that node
    for(int i=1;i<=m;i++){
        if(isSafe(node,colour,graph,n,i)){ //if it is safe to colour the node with i the colour it
            colour[node] = i;
            if(solve(node+1,colour,m,n,graph)) return true; //check for the other nodes
            colour[node] = 0;
        }
    }
    return false;
}
bool graphColouring(bool graph[101][101], int m, int n){
    int colour[n] = {0};
    if(solve(0,colour,m,n,graph)) return true;
    return false;
}
int main(){
    int n = 4;
    int m = 3;

    bool graph[101][101];
    
    memset(graph, false, sizeof graph);

    graph[0][1] = 1; graph[1][0] = 1; //edge (0,1)
    graph[1][2] = 1; graph[2][1] = 1; //edge (1,2)
    graph[2][3] = 1; graph[3][2] = 1; //edge (2,3)
    graph[3][0] = 1; graph[0][3] = 1; //edge (0,3)
    graph[0][2] = 1; graph[2][0] = 1; //edge (0,2)

    cout<<graphColouring(graph,m,n);
    return 0;
}