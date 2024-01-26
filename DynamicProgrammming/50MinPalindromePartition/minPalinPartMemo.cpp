#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int minPartitions(int i, int n, string &str, vector<int>& dp) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i == n) {
        return 0;
    }

    if(dp[i] != -1) return dp[i];

    int mini = INT_MAX;

    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,str)){
            int cost = 1 + minPartitions(j+1,n,str,dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}

int palindromePartitioning(string str) {
    int n = str.size();
    // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
    vector<int> dp(n,-1);
    return minPartitions(0, n, str,dp) - 1;
}

int main() {
    string str = "BABABCBADCEDE";
    int partitions = palindromePartitioning(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}
