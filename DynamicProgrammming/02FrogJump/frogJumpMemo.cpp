#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int n,vector<int>& height,vector<int>& dp){
    //base case
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    int jumpTwo = INT_MAX;
    int  jumpOne = climbingStairs(n-1,height,dp) + abs(height[n]-height[n-1]);
    if(n>1){
        jumpTwo = climbingStairs(n-2,height,dp) + abs(height[n]-height[n-2]);
    }
    return dp[n] = min(jumpOne,jumpTwo);
}
int main(){
    int n = 4;
    vector<int> height = {10,20,30,10};
    vector<int> dp(n,-1);
    cout<<"The minimum energy required "<<climbingStairs(n-1,height,dp);
    return 0;
}