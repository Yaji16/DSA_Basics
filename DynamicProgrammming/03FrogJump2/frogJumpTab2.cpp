#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int n,int k,vector<int>& height){
    //base case
    vector<int> dp(n);
    dp[0] = 0;
    
    for(int step = 1;step<n;step++){
        int minSteps = INT_MAX;
        for(int i=1;i<=k;i++){
            if(step-i>=0){
                int jump = dp[step-i] + abs(height[step-i]-height[step]);
                minSteps = min(minSteps,jump);
            }
        }
        dp[step] = minSteps;
    }
    
    return dp[n-1];
}
int main(){
    int n = 4;
    int k = 2;
    vector<int> height = {10,20,30,10};
    cout<<"The minimum energy required "<<climbingStairs(n-1,k,height);
    return 0;
}