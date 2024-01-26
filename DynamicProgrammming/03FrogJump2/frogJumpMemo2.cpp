#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int index,int k,vector<int>& height,vector<int>& dp){
    //base case
    if(index==0){
        return 0;
    }
    if(dp[index]!=-1) return dp[index];
    int minSteps = INT_MAX;
    for(int i=1;i<=k;i++){
        if(index-i>=0){
            int jump = climbingStairs(index-i,k,height,dp) + abs(height[index-i]-height[index]);
            minSteps = min(minSteps,jump);
        }
    }
    return dp[index]=minSteps;
}
int main(){
    int n = 4;
    int k = 2;
    vector<int> height = {10,20,30,10};
    vector<int> dp(n,-1);
    cout<<"The minimum energy required "<<climbingStairs(n-1,k,height,dp);
    return 0;
}