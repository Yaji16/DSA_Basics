#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,vector<vector<int>> &maze, vector<vector<int>>& dp){

    if(i>0 && j>0 && maze[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = solve(i-1,j,maze,dp);
    int left = solve(i,j-1,maze,dp);

    return dp[i][j] = up+left;
}

int mazeObstacles(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return solve(n - 1, m - 1, maze, dp); // Start from the bottom-right corner
}

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int n = maze.size();
    int m = maze[0].size();

    cout << "Number of paths with obstacles: " << mazeObstacles(n, m, maze) << endl;
    return 0;
}