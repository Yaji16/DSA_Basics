#include<bits/stdc++.h>
using namespace std;

int rodCutting(vector<int>& val, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0)); // Create a DP table
    
    for(int i=0;i<=n;i++){
        dp[0][i] = val[0]*(i+1);
    }

    for(int ind= 1;ind<n;ind++){
        for(int sum=0;sum<=n;sum++){
            int notTaken = dp[ind-1][sum];
            int taken = 0;
            if(sum-(ind+1)>0){
                taken = dp[ind][sum-(ind+1)];
            }
            dp[ind][sum] = max(taken,notTaken);
        }
    }
    
    return dp[n-1][n];
}

int main() {
    vector<int> val = {2, 5, 7, 8, 10}; // Value of lengths of rod
    
    int n = 5; // length of rod
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of rod by cutting is " << rodCutting(val,n) << endl;

    return 0; // Return 0 to indicate successful program execution
}