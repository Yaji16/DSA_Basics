#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> findOrder(int V,int m, vector<vector<int>> prerequisites){

        vector<int> adj[V];
        for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}

        vector<int> ans;
        int indegree[V] = {0};

        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size()==V) return ans;
        return {};
    }
};

int main() {

	int N = 4;
	int M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	Solution obj;
	vector<int> ans = obj.findOrder(N, M, prerequisites);

	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}