#include<bits/stdc++.h>
using namespace std;

bool canPartition(int n,vector<int>& arr){

    int totalSum = 0;
    for(int a: arr){
        totalSum += a;
    }

    if(totalSum%2) return false;
    
    int k = totalSum/2;
    vector<vector<bool>> dp(n, vector<bool>(k+1,false));

    // Base case:
    for(int i=0;i<n;i++){
        dp[i][0] = true; //if target is 0 we can achieve it by not taking any elememt
    }

    if(arr[0]<=k){
        dp[0][arr[0]] = true;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notTaken = dp[i-1][j];
            bool taken = false;
            if(arr[i]<=j){
                taken = dp[i-1][j-arr[i]];
            }
            dp[i][j] = notTaken || taken;
        }
    }
    return dp[n-1][k];
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