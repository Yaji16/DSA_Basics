#include<bits/stdc++.h>
using namespace std;

//day and the option of buy/sell keeps changing
//need to try out all options to see which can give the max profit
long getAns(vector<int>& prices,int n,int ind,int buy,int cap,vector<vector<vector<int>>>& dp){

    if(ind == n || cap == 0) return 0;
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    long profit = 0;
    //if buy is 0 then we can not do anything or we can buy stock
    if(buy == 0){
        profit = max(0+getAns(prices,n,ind+1,0,cap,dp), -prices[ind] + getAns(prices,n,ind+1,1,cap,dp));
    }
    //if buy is 0 we can not do anything or we can sell the stock
    if(buy == 1){
        profit = max(0+getAns(prices,n,ind+1,1,cap,dp), +prices[ind]+getAns(prices,n,ind+1,0,cap-1,dp));
    }

    return dp[ind][buy][cap] = profit;
}

int maximumProfit(vector<int>& prices, int n, int k) {
    // Creating a 3D DP array of size [n][2][k+1]
    vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>>(2, vector<int>(k + 1, -1)));

    return getAns(prices, n, 0, 0, k, dp);
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(prices, n, k) << endl;
    return 0;
}