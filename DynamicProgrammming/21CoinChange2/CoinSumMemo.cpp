#include<bits/stdc++.h>
using namespace std;

//the coin is changing and the sum is changing
//we can pick or not pick a coin

long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    if(ind == 0){
        return (T%arr[ind] == 0);
    }
    if(dp[ind][T] != -1) return dp[ind][T];

    int notTaken = countWaysToMakeChangeUtil(arr,ind-1,T,dp);
    int taken = 0;
    if(arr[ind]<=T){
        taken = countWaysToMakeChangeUtil(arr,ind,T-arr[ind],dp);
    }
    return dp[ind][T] = taken+notTaken;
}

long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the answer
    return countWaysToMakeChangeUtil(arr, n - 1, T, dp);
}

int main() {

    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();
    
    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;

    return 0; // Return 0 to indicate successful program execution
}