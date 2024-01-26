#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int>& arr,int ind,int buy, int n,int fee, vector<vector<int>>& dp){

    if(ind == n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy == 0){
        profit = max(getAns(arr,ind+1,0,n,fee,dp),-arr[ind] + getAns(arr,ind+1,1,n,fee,dp));
    }
    if(buy == 1){
        profit = max(getAns(arr,ind+1,1,n,fee,dp), arr[ind]-fee+getAns(arr,ind+1,0,n,fee,dp));
    }
    return dp[ind][buy] = profit;
}

int maximumProfit(int n, int fee, vector<int> &Arr) {
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    if (n == 0) return 0; // Edge case: No stocks to trade.
    
    int ans = getAns(Arr, 0, 0, n, fee, dp);
    return ans;
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;
                                 
    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}