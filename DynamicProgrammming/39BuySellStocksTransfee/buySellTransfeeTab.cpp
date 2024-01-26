#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int n, int fee, vector<int>& Arr) {
    if (n == 0) return 0; // Edge case: No stocks to trade.

    // Create a 2D DP array with dimensions (n+1) x 2, initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] - fee + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;
                                 
    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}

