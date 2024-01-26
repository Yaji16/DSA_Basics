#include<bits/stdc++.h>
using namespace std;

int rodCuttingUtil(int ind,vector<int>& val,int n,vector<vector<int>>& dp){
    if(ind==0){
        return val[0]*n;
    }
    if(dp[ind][n] != -1) return dp[ind][n];

    int notTaken = rodCuttingUtil(ind-1,val,n,dp);
    int taken = 0;
    if(n-(ind+1)>0){
        taken = val[ind] + rodCuttingUtil(ind,val,n-(ind+1),dp);
    }

    return dp[ind][n] = max(notTaken,taken);
}
int rodCutting(vector<int>& val, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the maximum value
    return rodCuttingUtil(n-1, val, n, dp);
}

int main() {
    vector<int> val = {2, 5, 7, 8, 10}; // Value of lengths of rod
    
    int n = 5; // length of rod
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of rod by cutting is " << rodCutting(val,n) << endl;

    return 0; // Return 0 to indicate successful program execution
}