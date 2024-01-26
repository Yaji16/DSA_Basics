#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>>& dp) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    for(int k=i;k<=j;k++){
        int ans = cuts[j+1]-cuts[i-1] + findMinimumCost(i,k-1,cuts,dp) + findMinimumCost(k+1,j,cuts,dp);
        mini = min(mini,ans);
    }
    return dp[i][j] = mini;
}
int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    // Call the recursive function to find the minimum cost.
    return findMinimumCost(1, c, cuts,dp);
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    cout << "The minimum cost incurred is: " << minimumCost(n, c, cuts) << endl;

    return 0;
}