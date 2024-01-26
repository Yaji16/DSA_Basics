#include<bits/stdc++.h>
using namespace std;

//the coin is changing and the sum is changing
//we can pick or not pick a coin
//keep track of the number of coins we are picking

int minimumElements(vector<int> arr,int T){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (T+1,0));

    for(int i=0; i<=T;i++){
        if(i % arr[0] == 0){
            dp[0][i] = i/arr[0];
        }else{
            dp[0][i] = 1e9;
        }
    }

    for(int ind = 1;ind<n;ind++){
        for(int t=0;t<=T;t++){
            int notTaken = dp[ind-1][t];
            int taken = 1e9;
            if(arr[ind]<=t){
                taken = 1 + dp[ind][t-arr[ind]];
            }
            dp[ind][t] = min(taken,notTaken);
        }
    }
    return dp[n-1][T];
}
int main() {

    vector<int> arr = {1, 2, 3};
    int T = 7;
                                 
    cout << "The minimum number of coins required to form the target sum is " << minimumElements(arr, T);

    return 0; // Return 0 to indicate successful program execution
}