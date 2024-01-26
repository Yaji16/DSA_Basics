#include<bits/stdc++.h>
using namespace std;

bool solve(int n,int k,vector<int>& arr,int ind,vector<vector<int>> &dp){
    
    //Base case:
    if(ind == 0) return arr[ind]==k;
    if(k == 0) return true;
    if(dp[ind][k] != -1) return dp[ind][k];

    bool notTaken = solve(n,k,arr,ind-1,dp);
    bool taken= false;
    if(arr[ind]<=k){
        taken = solve(n,k-arr[ind],arr,ind-1,dp);
    }

    return dp[ind][k] = notTaken || taken;
}
bool subsetSumToK(int n,int k,vector<int>& arr){
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return solve(n,k,arr,n-1,dp);
}
int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}