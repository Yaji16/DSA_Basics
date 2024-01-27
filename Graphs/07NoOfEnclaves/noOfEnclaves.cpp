#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numberOfEnclaves(vector<vector<int>>grid)
	{
	    int n = grid.size(); 
	    int m = grid[0].size(); 

        vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    
        queue<pair<int,int>> q; //coordinates

        //traverse the boundary elements
        for(int i = 0;i<n;i++){
	        for(int j = 0;j<m;j++){
                if( i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
           
            q.pop();
                        
            for(int i=0;i<4;i++){
                int drow = row + delrow[i];
                int dcol = col + delcol[i];

                if(drow>=0 && drow<n && dcol>=0 && dcol<m && vis[drow][dcol] == 0 && grid[drow][dcol]==1){
                    vis[drow][dcol] = 1;
                    q.push({drow,dcol});
                }
            }
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
	        for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    } 
};

int main() {
    
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
        
    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;

}