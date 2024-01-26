#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {
    // Create a 2D DP array initialized to -1
    if(n == 0) return 0;

    vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

    for(int ind=n-1;ind>=0;ind--){
        for(int prev=ind-1;prev>=-1;prev--){
            int notTake = dp[ind+1][prev+1];
            int take = 0;
            if( prev==-1 || arr[ind]>arr[prev]){
                take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev+1] = max(notTake, take);
        }
    }
    
    return dp[0][0];
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n);
    
    return 0;
}