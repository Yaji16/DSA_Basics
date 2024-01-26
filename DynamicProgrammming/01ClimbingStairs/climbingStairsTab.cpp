#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int n){

    vector<int> dp(n+1);
    //base case
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n = 4;
    
    cout<<"The no: of ways to climb "<<n<<" stairs is "<<climbingStairs(n);
    return 0;
}