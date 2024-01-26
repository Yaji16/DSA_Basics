#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,vector<vector<int>>& dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = solve(i-1,j,dp);
    int left = solve(i,j-1,dp);
    return dp[i][j] = up+left;
}
int countWays(int m,int n){
    vector<vector<int>> dp(m,vector<int> (n,-1));
    return solve(m-1,n-1,dp);
}

int main() {
    int m = 3;
    int n = 2;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}