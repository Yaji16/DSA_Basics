#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int> arr,int k){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));

    if(arr[0]<=k){
        dp[0][arr[0]] = 1;
    }
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    for(int ind = 1;ind<n;ind++){
        for(int sum = 1;sum<=k;sum++){
            int notTaken = dp[ind-1][sum];
            int taken = 0;
            if(arr[ind]<=sum){
                taken = dp[ind-1][sum-arr[ind]];
            }
            dp[ind][sum] = taken + notTaken;
        }
    }

    return dp[n-1][k];
}

int main(){
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}