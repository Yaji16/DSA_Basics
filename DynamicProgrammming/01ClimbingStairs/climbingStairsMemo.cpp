#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int n,vector<int>& dp){
    //base case
    if(n<=1){
        return 1;
    }
    if(dp[n]!=-1) return dp[n]; //if subproblem is already solved then use the answer
    return dp[n] = climbingStairs(n-1,dp)+climbingStairs(n-2,dp);
}
int main(){
    int n = 4;
    vector<int> dp(n+1,-1);
    cout<<"The no: of ways to climb "<<n<<" stairs is "<<climbingStairs(n,dp);
    return 0;
}