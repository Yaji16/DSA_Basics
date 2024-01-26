#include <bits/stdc++.h>
using namespace std;

int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>>& dp) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int maxi = INT_MIN;

    for(int k=i;k<=j;k++){
        int ans = nums[i-1]*nums[k]*nums[j+1] + maxCoinsHelper(i,k-1,nums,dp) + maxCoinsHelper(k+1,j,nums,dp);
        maxi = max(maxi,ans);
    }
    return dp[i][j] = maxi;
}

int maxCoins(vector<int> &nums) {
    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n,vector<int> (n,-1));
    // Call the helper function to compute the maximum coins
    return maxCoinsHelper(1, n, nums,dp);
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    int maxCoinsResult = maxCoins(nums);
    cout << "Maximum coins obtained: " << maxCoinsResult << "\n";
    
    return 0;
}
