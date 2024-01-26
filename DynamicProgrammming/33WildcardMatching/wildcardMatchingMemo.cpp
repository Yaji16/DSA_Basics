#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string s1,int i){
    for(int k=0;k<=i;k++){
        if(s1[k] != '*') return false;
    }
    return true;
}
bool wildcardMatchingUtil(string s1,string s2,int i,int j,vector<vector<bool>>& dp){
    //Base case:
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(i>=0 && j<0){
        return isAllStars(s1,i);
    }
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j] || s1[i] == '?'){
        return dp[i][j] = wildcardMatchingUtil(s1,s2,i-1,j-1,dp);
    }else{
        if(s1[i] == '*'){
            return  dp[i][j] = wildcardMatchingUtil(s1,s2,i,j-1,dp) || wildcardMatchingUtil(s1,s2,i-1,j,dp);
        }else{
            return false;
        }
    }
}

bool wildcardMatching(string s1,string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<bool>> dp(n,vector<bool> (m,-1));
    return wildcardMatchingUtil(s1,s2,n-1,m-1,dp);
}

int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}