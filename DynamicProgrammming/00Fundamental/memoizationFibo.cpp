#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int fibonacciMemo(int n,vector<int>& dp){
        //base case
        if(n<=1){
            return n; 
        }
        if(dp[n] != -1) {return dp[n];}
        return dp[n] = fibonacciMemo(n-1,dp)+fibonacciMemo(n-2,dp);
    }
};
int main(){
    Solution obj;
    int n = 6;
    vector<int> dp(n+1,-1);
    
    cout<<"The "<<n<<"th fibonacci number is ";
    int ans = obj.fibonacciMemo(n,dp);
    cout<< ans;
    return 0;
}