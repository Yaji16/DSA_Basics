#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,vector<vector<int>> &mat, vector<vector<int>>& dp){

    if(i==0 && j==0) return mat[i][j];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = mat[i][j]+solve(i-1,j,mat,dp);
    int left = mat[i][j]+solve(i,j-1,mat,dp);

    return dp[i][j] = min(up,left);
}

int minSumPath(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return solve(n - 1, m - 1, mat, dp); // Start from the bottom-right corner
}

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}