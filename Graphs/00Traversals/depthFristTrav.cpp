#include<bits/stdc++.h>
using namespace std;

class Solution{

    private:
    void dfs(int node,vector<int> adj[],int vis[], vector<int>& ls){
        vis[node] = 1; //mark node as visited
        ls.push_back(node);

        for(auto it: adj[node]){ //traverse neighbours
            if(!vis[it]){ //if not visited perform dfs
                dfs(it,adj,vis,ls);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int V,vector<int> adj[]){
        vector<int> ls;
        int vis[V] = {0}; //visted array
        int start = 0; //start node
        dfs(start, adj, vis, ls);
        return ls;
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}