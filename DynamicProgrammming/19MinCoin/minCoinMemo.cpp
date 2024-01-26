#include<bits/stdc++.h>
using namespace std;

//the coin is changing and the sum is changing
//we can pick or not pick a coin
//keep track of the number of coins we are picking

int minimumElementsUtil(int ind,vector<int>& arr,int T,vector<vector<int>>& dp){
    if(ind == 0){
        if(T % arr[0] == 0) return T/arr[0];
        return 1e9;
    }
    if(dp[ind][T] != -1) return dp[ind][T];

    int notTaken = minimumElementsUtil(ind-1,arr,T,dp);
    int taken = INT_MAX;
    if(arr[ind]<=T){
        taken = 1 + minimumElementsUtil(ind,arr,T-arr[ind],dp);
    }
    return dp[ind][T] = min(taken,notTaken);
}
int minimumElements(vector<int> arr,int T){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (T+1,-1));
    return minimumElementsUtil(n-1,arr,T,dp);
}
int main() {

    vector<int> arr = {1, 2, 3};
    int T = 7;
                                 
    cout << "The minimum number of coins required to form the target sum is " << minimumElements(arr, T);

    return 0; // Return 0 to indicate successful program execution
}