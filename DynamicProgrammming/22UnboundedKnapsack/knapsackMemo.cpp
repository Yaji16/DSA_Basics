#include<bits/stdc++.h>
using namespace std;

// no constraints pick up all elements
// if wt<=curr_capacity we can pick or not pick
// weight of bag changes, the item changes
int knapsackUtil(int ind,vector<int>& wt,vector<int>& val,int W,vector<vector<int>>& dp){

    if(ind == 0){
        return (W % wt[ind] == 0) ? val[ind]*(W/wt[ind]):0;
    }
    if(dp[ind][W] != -1) return dp[ind][W];

    int notTaken = knapsackUtil(ind-1,wt,val,W,dp);
    int taken = INT_MIN;
    if(wt[ind] <= W){
        taken = val[ind] + knapsackUtil(ind,wt,val,W-wt[ind],dp);
    }
    return dp[ind][W] = max(taken,notTaken);
}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); 

    return knapsackUtil(n - 1, wt, val, W, dp);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}