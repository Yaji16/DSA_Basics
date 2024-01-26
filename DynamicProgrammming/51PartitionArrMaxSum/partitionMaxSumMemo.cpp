#include <bits/stdc++.h>
using namespace std;

int solve(int i,vector<int>& num, int k, vector<int>& dp){
    int n = num.size();

    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxi = max(maxi,num[j]);
        int sum = (maxi * len) + solve(j+1,num,k,dp);
        maxAns = max(maxAns, sum);
    }
    return dp[i] = maxAns;
}

int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    vector<int> dp(n, -1);
    return solve(0, num, k, dp);
}

int main() {
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int maxSum = maxSumAfterPartitioning(num, k);
    cout << "The maximum sum is: " << maxSum << "\n";
    return 0;
}
