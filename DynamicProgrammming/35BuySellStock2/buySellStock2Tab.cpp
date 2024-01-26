#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *Arr, int n) {
    // Create a DP table to memoize results
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = dp[n][1] = 0;

    long profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
}

int main() {
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}

