#include<bits/stdc++.h>
using namespace std;
//Given an undirected graph, 
//return a vector of all nodes by traversing the graph using breadth-first search (BFS).

//breadth first search - level wise traversal, the starting node can be anything
// the nodes which are at an equivalent distance to the starting node
class Solution{
    public:
    vector<int> bfsOfGraph(int V,vector<int> adj[]){ //SC O(3N) TC O(N) -queue + O(2E) - total degrees
        vector<int> bfs; //stores the bfs traversal
        queue<int> q; //FIFO
        int visited[V] = {0}; //track of the nodes which are visited while traversing

        q.push(0);//push the starting node in queue
        visited[0] = 1; //mark as visited

        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it: adj[node]){ //who are your neighbours?
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
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
    vector <int> adj[6]; //adjacency list
    
    addEdge(adj, 0, 1); //the connected edges
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj); // 5 nodes, adjacency list needed
    printAns(ans);

    return 0;
}

