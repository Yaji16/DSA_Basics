#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int longestPalindromeSubsequence(string s){
    string t = s;
    reverse(s.begin(),s.end());

    return lcs(s,t);
}

int minInsertion(string s) {
    int n = s.size();
    int k = longestPalindromeSubsequence(s);

    // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return n - k;
}

int main() {
    string s = "abcaa";
    
    // Call the minInsertion function and print the result
    cout << "The Minimum insertions required to make string palindrome: " << minInsertion(s);
    return 0;
}