#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(); 
	    int m = grid[0].size(); 

        vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 

        queue<pair<pair<int,int>, int>> q; //coordinates & steps taken

        for(int i = 0;i<n;i++){
	        for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();
            dist[row][col] = steps;
            
            for(int i=0;i<4;i++){
                int drow = row + delrow[i];
                int dcol = col + delcol[i];

                if(drow>=0 && drow<n && dcol>=0 && dcol<m && vis[drow][dcol] == 0){
                    vis[drow][dcol] = 1;
                    q.push({{drow,dcol},steps+1});
                }
            }
        }
        return dist;
    } 
};

int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	Solution obj;
	vector<vector<int>> ans = obj.nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}