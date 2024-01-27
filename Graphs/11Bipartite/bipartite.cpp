#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool dfs(int node,int col,int colour[],vector<int> adj[]){
        colour[node] = col;

        for(auto it: adj[node]){
            if(colour[node]==-1){
                if(dfs(it,!col,colour,adj) == false) return false;
            }
            else if(colour[it] == col){
                return false;
            }
        }
        return true;
    }
    public:
    bool isBipartite(int V,vector<int> adj[]){
        int colour[V] ={-1};

        for(int i=0;i<V;i++){
            if(colour[i] == -1){
                if(dfs(i,0,colour,adj)==false) return false;
            }
        }
        return true;
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
	
	// V = 4, E = 4
	vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

	Solution obj;
	bool ans = obj.isBipartite(4, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	
	return 0;
}