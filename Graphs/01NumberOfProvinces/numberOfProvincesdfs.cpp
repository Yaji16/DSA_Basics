#include<bits/stdc++.h>
using namespace std;

class Solution{ // Tc O(N) + O(V+2E)
    private:
    void dfs(int node,vector<int> adjLs[],int vis[]){
        vis[node] = 1;

        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }

    }
    public:
    int numProvinces(vector<vector<int>> adj, int V){
        //making adjacency list

        vector<int> adjLs[V];

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[V] = {0};
        int cnt = 0;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        return cnt;
    }

};
int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << ob.numProvinces(adj,3) << endl;
        
    return 0;
}