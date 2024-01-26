#include <bits/stdc++.h>

using namespace std;

const int prime = 1e9 + 7;

int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // If s2 has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;
    
    // If s1 has been completely traversed but s2 hasn't, return 0
    if (ind1 < 0)
        return 0;

    // If the result for this state has already been calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    // If the characters match, consider two options: either leave one character in s1 and s2
    // or leave one character in s1 and continue matching s2
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;
    } else {
        // If characters don't match, just leave one character in s1 and continue matching s2
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }

    // Store the result and return it
    dp[ind1][ind2] = result;
    return result;
}

int subsequenceCounting(string &s1, string &s2, int lt, int ls) {
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return countUtil(s1, s2, lt - 1, ls - 1, dp);
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}