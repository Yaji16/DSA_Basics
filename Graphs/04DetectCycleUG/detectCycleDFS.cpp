#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool dfs(int node,int parent, vector<int> adj[],int vis[]){
        vis[node] = 1;
        for(int adjnode: adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode,node,adj,vis) == true) return true;
            }
            else if(parent != adjnode){
                return true;
            }
        }
        return false;
    }
    public:
    bool isCycle(int V,vector<int> adj[]){
        int vis[V] = {0};
        for(int i=0; i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }
};
int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}