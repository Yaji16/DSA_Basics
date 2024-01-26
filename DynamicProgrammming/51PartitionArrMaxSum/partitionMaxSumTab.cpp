#include <bits/stdc++.h>
using namespace std;


int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    vector<int> dp(n+1, 0);
   
    for(int i=n-1;i>=0;i--){
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(maxi,num[j]);
            int sum = (maxi * len) + dp[j+1];
            maxAns = max(maxAns, sum);
        }
        dp[i] = maxAns;
    }
    return dp[0];
}

int main() {
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int maxSum = maxSumAfterPartitioning(num, k);
    cout << "The maximum sum is: " << maxSum << "\n";
    return 0;
}
