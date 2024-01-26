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
bool canPartition(int n,vector<int>& arr){
    int sum = 0;
    for(int a: arr){
        sum += a;
    }
    if(sum % 2){ 
        return false;
    }else{
        vector<vector<int>> dp(n, vector<int>((sum/2)+1,-1));
        return solve(n,sum/2,arr,n-1,dp);
    }
}
int main() {
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (canPartition(n, arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}