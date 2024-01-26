#include<bits/stdc++.h>
using namespace std;

int findWaysUtil(int ind,int k,vector<int> arr,vector<vector<int>> &dp){

    if(ind == 0 ) return (arr[ind]==k)?1:0;
    if(k == 0) return 1; 

    //if the target/k is 0 or if array has elements with 0 then follow this base conditions
    // if(ind == 0){
    //         if(k==0 && arr[0]==0)
    //             return 2;
    //         if(k==0 || k == arr[0])
    //             return 1;
    //         return 0;
    // }
    if(dp[ind][k] != -1) return dp[ind][k];

    int notTaken = findWaysUtil(ind-1,k,arr,dp);
    int taken = 0;
    if(arr[ind<=k]){
        taken = findWaysUtil(ind-1,k-arr[ind],arr,dp);
    }
    return dp[ind][k] = taken + notTaken;
}

int findWays(vector<int> arr,int k){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,arr,dp);
}

int main(){
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}