#include<bits/stdc++.h>
using namespace std;

int solve(int m,int n,vector<vector<int>>& maze){
    vector<vector<int>> dp(m,vector<int> (n,-1));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(i==0 && j==0){
                dp[i][j] = 1;
                continue;
            }
            if(maze[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            int up = 0;
            int left = 0;

            if(i>0){
                up = dp[i-1][j];
            }
            if(j>0){
                left = dp[i][j-1];
            }
            dp[i][j] = up+left;
        }
    }

    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int n = maze.size();
    int m = maze[0].size();

    cout << "Number of paths with obstacles: " << solve(n, m, maze) << endl;
    return 0;
}