#include<bits/stdc++.h>
using namespace std;

// no constraints pick up all elements
// if wt<=curr_capacity we can pick or not pick
// weight of bag changes, the item changes

int knapsack(vector<int> wt,vector<int> val,int n, int W){
    vector<vector<int>> dp(n,vector<int> (W+1,0));
    
    for(int i=wt[0];i<=W;i++){ // if the first item has weight less than W fill the row with that value
        dp[0][i] = (i / wt[0]) * val[0]; 
    }
    
    for(int ind = 1;ind<n;ind++){
        for(int cap = 0; cap <=W; cap++){
            int notTaken = dp[ind-1][cap];
            int taken = INT_MIN;
            if(wt[ind] <= cap){
                taken = val[ind] + dp[ind][cap-wt[ind]];
            }
            dp[ind][cap] = max(taken,notTaken);
        }
    }

    return dp[n-1][W];
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items

    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << knapsack(wt,val,n, W) << endl;

    return 0;
}