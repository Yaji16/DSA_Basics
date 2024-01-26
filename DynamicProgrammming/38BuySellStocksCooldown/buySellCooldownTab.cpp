

#include <bits/stdc++.h>
using namespace std;

int stockProfit(vector<int> &Arr) {
    int n = Arr.size();
    // Create a 2D DP array with dimensions (n+2) x 2, initialized to 0
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    
    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 2][0]);
            }

            // Store the computed profit in the DP array
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

int main() {
    vector<int> prices {4, 9, 0, 4, 10};
                                 
    cout << "The maximum profit that can be generated is " << stockProfit(prices) << endl;
    return 0;
}

