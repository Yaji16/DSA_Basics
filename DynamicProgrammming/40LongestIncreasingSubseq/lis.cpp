#include<bits/stdc++.h>
using namespace std;

int getAns(int arr[],int n,int ind,int prev,vector<vector<int>>& dp){

    if(ind == n) return 0;

    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

    int notTake = getAns(arr,n,ind+1,prev,dp);
    int take = 0;
    if(prev==-1 || arr[ind]>arr[prev]){
        take = 1 + getAns(arr,n,ind+1,ind,dp);
    }
    return dp[ind][prev + 1] = max(notTake, take);
}
int longestIncreasingSubsequence(int arr[], int n) {
    // Create a 2D DP array initialized to -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    return getAns(arr, n, 0, -1, dp);
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n);
    
    return 0;
}