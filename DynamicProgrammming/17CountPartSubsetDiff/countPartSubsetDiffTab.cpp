#include<bits/stdc++.h>
using namespace std;

int countPartitions(int d,vector<int> arr){

    int mod =(int)1e9+7;
    int totSum = 0;
    int n = arr.size();
    
    for(int a: arr){
        totSum += a;
    }
    if(totSum-d<0) return 0;
    if((totSum-d)%2) return 0;
 
    int k = (totSum-d)/2;

    vector<vector<int>> dp(n,vector<int> (k+1,0));

    if(arr[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]] = 1;  // 1 case -pick

    for(int ind=1;ind<n;ind++){
        for(int sum=1;sum<=k;sum++){
            int notTaken = dp[ind-1][sum];
            int taken = 0;
            if(arr[ind]<=sum){
                taken = dp[ind-1][sum-arr[ind]];
            }
            dp[ind][sum] = (taken+notTaken)%mod;
        }
    }


    return dp[n-1][k];
}
int main(){
    vector<int> arr = {5,2,6,4};
    int d=3;
                                 
    cout<<"The number of subsets found are " <<countPartitions(d,arr);
    return 0;
}