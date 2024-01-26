#include<bits/stdc++.h>
using namespace std;

int maxSum(int n,vector<int>& arr,vector<int>& dp){
    //base case
    dp[0] = arr[0]; // prev = arr[0], prev2 = 0
    
    for(int i=1;i<n;i++){
        int pick = arr[i];
        if(i>1){
            pick += dp[i-2]; // pick += prev2
        }
        int notPick = dp[i-1]; // notPick = prev

        dp[i] = max(pick,notPick); // cur = max(pick,notPick)
        //prev2 = prev
        //prev = cur - space optimization method
    }
    return dp[n-1];
}
int solve(int n, vector<int>& arr) {
    vector<int> dp(n,0);
    return maxSum(n, arr,dp); 
}
int main(){
    int n = 4;
    vector<int> arr = {2,1,4,9};
    cout<<"The maximum sum from non adjacent elements "<<solve(n,arr);
    return 0;
}