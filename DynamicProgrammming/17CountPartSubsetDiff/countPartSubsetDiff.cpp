#include<bits/stdc++.h>
using namespace std;

int mod =(int)1e9+7;

int countPartitionsUtil(int ind,int k,vector<int> &arr,vector<vector<int>> &dp){
    if(ind == 0){
        if(k==0 && arr[0]==0) return 2;
        if(k==0 || arr[0]==k) return 1;
        return 0;
    }
    if(dp[ind][k] != -1) return dp[ind][k];

    int notTaken = countPartitionsUtil(ind-1,k,arr,dp);
    int taken = 0;
    if(arr[ind]<=k){
        taken = countPartitionsUtil(ind-1,k-arr[ind],arr,dp);
    }
    return dp[ind][k] = (taken+notTaken)%mod;
}

int countPartitions(int d,vector<int> arr){
    int totSum = 0;
    int n = arr.size();
    
    for(int a: arr){
        totSum += a;
    }
    if(totSum-d<0) return 0;
    if((totSum-d)%2) return 0;

    int k = (totSum-d)/2;

    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return countPartitionsUtil(n-1,k,arr,dp);
}
int main(){
    vector<int> arr = {5,2,6,4};
    int d=3;
                                 
    cout<<"The number of subsets found are " <<countPartitions(d,arr);
    return 0;
}