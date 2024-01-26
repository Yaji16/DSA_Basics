#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> arr, int n){
    int totSum = 0;
    for(int a: arr){
        totSum += a;
    }
    vector<vector<bool>> dp(n, vector<bool>(totSum+1,false));

    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    if(arr[0]<=totSum){
        dp[0][arr[0]] = true;
    }

    for(int ind = 1;ind<n;ind++){
        for(int sum = 1;sum<=totSum;sum++){
            bool notTaken = dp[ind-1][sum];

            bool taken = true;
            if(arr[ind] <= sum){
                taken = dp[ind-1][sum-arr[ind]];
            }

            dp[ind][sum] = taken || notTaken;
        }
    }

    int mini = INT_MAX;
    for(int i=0;i<=totSum;i++){
        if (dp[n - 1][i] == true) { //if sum 'i' is achievable find the minimum difference
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }

    return mini;

}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

    return 0;
}