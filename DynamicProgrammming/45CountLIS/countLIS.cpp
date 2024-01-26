#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> arr){
    int n = arr.size();
    
    vector<int> dp(n,1);
    vector<int> cnt(n,1);

    int maxi = 1;
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            if(arr[i]>arr[prev_index] && 1+dp[prev_index]>dp[i]){
                dp[i] = 1 + dp[prev_index];
                cnt[i] = cnt[prev_index];
            }
            else if(arr[i]>arr[prev_index] && 1+dp[prev_index]==dp[i]){
                cnt[i] += cnt[prev_index];
            }
        }
        maxi = max(maxi,dp[i]);
    }

      
    int count = 0;

    for(int i=0;i<n;i++){
        if(dp[i] == maxi){
            count += cnt[i];
        }
    }
     
    return count;
}

int main() {
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};

    cout << "The count of Longest Increasing Subsequences (LIS) is " << findNumberOfLIS(arr) << endl;

    return 0;
}