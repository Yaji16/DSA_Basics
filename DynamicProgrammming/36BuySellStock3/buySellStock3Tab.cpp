#include <bits/stdc++.h>
using namespace std;

long maxProfit(vector<int>& prices,int n){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base case: dp array is already initialized to 0, covering the base case.

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                //if buy is 0 then we can not do anything or we can buy stock
                if(buy == 0){
                    dp[ind][buy][cap] = max(dp[ind+1][0][cap], -prices[ind] + dp[ind+1][1][cap]);
                }
                //if buy is 0 we can not do anything or we can sell the stock
                if(buy == 1){
                    dp[ind][buy][cap] = max(0+dp[ind+1][1][cap], +prices[ind]+dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    // Call the recursive function to calculate maximum profit
    return dp[0][0][2];
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    // Call the maxProfit function and print the result
    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}

