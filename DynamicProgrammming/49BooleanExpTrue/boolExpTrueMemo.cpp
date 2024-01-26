#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

int solve(int i, int j, int isTrue, string &exp, vector<vector<int>>& dp) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    if(i==j){
        if(isTrue){ return exp[i]=='T' ? 1: 0;}
        else{ return exp[i]=='F' ? 1:0;}
    }

    if(dp[i][j] != -1) return dp[i][j];

    ll ways = 0;
    for(int k=i+1;k<=j-1;k+=2){
        ll lT = solve(i,k-1,1,exp,dp);
        ll lF = solve(i,k-1,0,exp,dp);
        ll rT = solve(k+1,j,1,exp,dp);
        ll rF = solve(k+1,j,0,exp,dp);

        if(exp[k] == '&'){
            if(isTrue){
                ways = (ways + (lT*rT) % mod) % mod;
            }else{
                ways = (ways + (lT*rF) % mod + (lF*rT) % mod + (lF*rF) % mod) % mod;
            }
        }
        else if(exp[k] == '|'){
            if(isTrue){
                ways = (ways + (lT*rF) % mod + (lF*rT) % mod + (lT*rT) % mod) % mod;
            }else{
                ways = (ways + (lF*rF) % mod) % mod;
            }
        }
        else{
            if(isTrue){
                ways = (ways + (lT*rF) % mod + (lF*rT) % mod) % mod;
            }else{
                ways = (ways + (lF*rF) % mod + (lT*rT) % mod) % mod;
            }
        }
    }
    return dp[i][j] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    return solve(0, n - 1, 1, exp, dp);  // Start evaluation with isTrue set to true.
}

int main() {
    string exp = "F|T^F";
    int ways = evaluateExp(exp);
    cout << "The total number of ways: " << ways << "\n";
    return 0;
}

