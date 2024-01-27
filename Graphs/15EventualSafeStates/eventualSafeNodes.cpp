#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> eventualSafeNodes(int V,vector<int> adj[]){
        vector<int> adjRev[V];
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                adjRev[it].push_back(i);
            }
        }
        int indegree[V] = {0};
        queue<int> q;

        for(int i=0;i<V;i++){
            for(auto it: adjRev[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};

int main() {

	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}