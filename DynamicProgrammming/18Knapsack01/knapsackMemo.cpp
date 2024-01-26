#include<bits/stdc++.h>
using namespace std;

// no constraints pick up all elements
// if wt<=curr_capacity we can pick or not pick
// weight of bag changes, the item changes
int knapsackSolve(int ind,vector<int>& wt,vector<int>& val,int W,vector<vector<int>>& dp){

    if(ind == 0){
        return (wt[ind]<=W) ? val[ind]:0;
    }
    if(dp[ind][W] != -1) return dp[ind][W];

    int notTaken = knapsackSolve(ind-1,wt,val,W,dp);
    int taken = INT_MIN;
    if(wt[ind] <= W){
        taken = val[ind] + knapsackSolve(ind-1,wt,val,W-wt[ind],dp);
    }
    return dp[ind][W] = max(taken,notTaken);
}

int knapsack(vector<int> wt,vector<int> val,int n, int W){
    vector<vector<int>> dp(n,vector<int> (W+1,-1));
    return knapsackSolve(n-1,wt,val,W,dp);
}

int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}