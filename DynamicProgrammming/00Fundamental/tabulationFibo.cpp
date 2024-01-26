#include<bits/stdc++.h>
using namespace std;

int fibonacciTab(int n){
    vector<int> dp(n+1,-1);
    //base case
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n = 6;
    cout<<"The "<<n<<"th fibonacci number is "<<fibonacciTab(n);
    return 0;
}