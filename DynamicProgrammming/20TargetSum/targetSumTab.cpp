#include<bits/stdc++.h>
using namespace std;

//the numbers are changing, the target sum is changing
int targetSum(int n, int target, vector<int>& arr) {
    int mod = (int)1e9+7;
    int totSum = 0;
    for(int i=0;i<n;i++){
        totSum += arr[i];
    }
    // s1 + s2 = target
    // s1 - s2 = totSum
    // s2 = (totSum - target)/2

    if(totSum - target < 0) return 0;
    if((totSum - target)%2) return 0;
    int k = (totSum-target)/2;

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    if(arr[0] == 0){
        dp[0][0] = 2;
    }else{
        dp[0][0] = 1;
    }

    if(arr[0]!=0 && arr[0]<=k){
        dp[0][arr[0]] = 1;
    }

    for(int ind = 1;ind<n;ind++){
        for(int t=0;t<=k;t++){
            int notTaken = dp[ind-1][t];
            int taken = 0;
            if(arr[ind]<=t){
                taken = dp[ind-1][t-arr[ind]];
            }
            dp[ind][t] = (taken + notTaken)%mod;
        }
    }
    return dp[n-1][k];
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    int target = 3;
                     
    int n = arr.size();
    cout << "The number of ways found is " << targetSum(n, target, arr) << endl;
    
    return 0; // Return 0 to indicate successful program execution
}