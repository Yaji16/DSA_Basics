#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void dfs(int node,vector<int> adj[],int vis[],stack<int>& st){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    public:
    vector<int> topoSort(int V,vector<int> adj[]){
        int vis[V] = {0};
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
               dfs(i, adj, vis,st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}