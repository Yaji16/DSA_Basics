#include <bits/stdc++.h>
using namespace std;

int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){

            if(i>j) continue;
            
            int mini = INT_MAX;

            for(int k=i;k<=j;k++){
                int ans = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini,ans);
            }
            dp[i][j] = mini;
        }
    }
    // Call the recursive function to find the minimum cost.
    return dp[1][c];
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    cout << "The minimum cost incurred is: " << minimumCost(n, c, cuts) << endl;

    return 0;
}