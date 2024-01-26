#include<bits/stdc++.h>
using namespace std;

int solve(int m,int n){
    vector<vector<int>> dp(m,vector<int> (n,-1));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(i==0 && j==0){
                dp[i][j] = 1;
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

int countWays(int m,int n){
    return solve(m,n);
}

int main() {
    int m = 3;
    int n = 2;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}