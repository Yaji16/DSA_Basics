#include <bits/stdc++.h>
using namespace std;


int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j=0;j<m;j++){
        dp[0][j] = arr[0][j];
    }

    for(int i=0;i<n;i++){
        dp[i][0] = arr[i][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }

    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            count += dp[i][j];
        }
    }
    return count;
}

int main() {

    vector<vector<int>> arr = {
        {0, 1, 1, 1}, {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int n = 3, m = 4;
    int squares = countSquares(n, m, arr);
    cout << "The number of squares: " << squares << "\n";
    return 0;
}
