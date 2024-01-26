#include<bits/stdc++.h>
using namespace std;

// no constraints pick up all elements
// if wt<=curr_capacity we can pick or not pick
// weight of bag changes, the item changes

int knapsack(vector<int> wt,vector<int> val,int n, int W){
    vector<vector<int>> dp(n,vector<int> (W+1,0));
    
    for(int i=wt[0];i<=W;i++){ // if the first item has weight less than W fill the row with that value
        dp[0][i] = val[0];
    }
    
    for(int ind = 1;ind<n;ind++){
        for(int cap = 0; cap <=W; cap++){
            int notTaken = dp[ind-1][cap];
            int taken = INT_MIN;
            if(wt[ind] <= cap){
                taken = val[ind] + dp[ind-1][cap-wt[ind]];
            }
            dp[ind][cap] = max(taken,notTaken);
        }
    }

    return dp[n-1][W];
}

int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}