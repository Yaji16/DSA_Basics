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
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n - 1; j++) {
            // Base case 1: i > j is an invalid case, so continue.
            if (i > j) continue;
            
            for (int isTrue = 0; isTrue <= 1; isTrue++) {

                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                ll ways = 0;
                for(int k=i+1;k<=j-1;k+=2){
                    ll lT = dp[i][k-1][1];
                    ll lF = dp[i][k-1][0];
                    ll rT = dp[k+1][j][1];
                    ll rF = dp[k+1][j][0];

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
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n-1][1];  // Start evaluation with isTrue set to true.
}

int main() {
    string exp = "F|T^F";
    int ways = evaluateExp(exp);
    cout << "The total number of ways: " << ways << "\n";
    return 0;
}

