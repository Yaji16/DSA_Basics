#include<bits/stdc++.h>
using namespace std;

bool solve(int ind,int k,vector<int>& arr,vector<vector<int>> &dp){
    
    //Base case:
    if(ind == 0) return dp[ind][k] = (arr[ind]==k);
    if(k == 0) return dp[ind][k] = true;
    if(dp[ind][k] != -1) return dp[ind][k];

    bool notTaken = solve(ind-1,k,arr,dp);
    bool taken= false;
    if(arr[ind]<=k){
        taken = solve(ind-1,k-arr[ind],arr, dp);
    }

    return dp[ind][k] = notTaken || taken;
}
int minSubsetSumDifference(vector<int> arr, int n){
    int totSum = 0;
    for(int a: arr){
        totSum += a;
    }
    vector<vector<int>> dp(n, vector<int>(totSum+1,-1));

    //calculate the subset sum from each possible sum from 0 to totalSum
    for(int i=0;i<=totSum;i++){
        bool dummy = solve(n-1,i,arr,dp);
    }
    int mini = INT_MAX;
    for(int i=0;i<=totSum;i++){
        if (dp[n - 1][i] == true) { //if sum 'i' is achievable find the minimum difference
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }

    return mini;
}
int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

    return 0;
}