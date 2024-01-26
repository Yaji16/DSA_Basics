#include<bits/stdc++.h>
using namespace std;

//day and the option of buy/sell keeps changing
//need to try out all options to see which can give the max profit
long getAns(long *arr,int ind,int buy,int n,vector<vector<long>>& dp){
    if(ind == n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    long profit = 0;
    //if buy is 0 then we can not do anything or we can buy stock
    if(buy == 0){
        profit = max(0+getAns(arr,ind+1,0,n,dp), -arr[ind] + getAns(arr,ind+1,1,n,dp));
    }
    //if buy is 0 we can not do anything or we can sell the stock
    if(buy == 1){
        profit = max(0+getAns(arr,ind+1,1,n,dp), +arr[ind]+getAns(arr,ind+1,0,n,dp));
    }

    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *arr,int n){
    vector<vector<long>> dp(n, vector<long>(2, -1));

    if (n == 0) {
        return 0;
    }

    long ans = getAns(arr, 0, 0, n, dp);
    return ans;
}

int main() {
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}