#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int>& arr,int n){
    
    vector<vector<int>> dp(n,vector<int> (n,-1));

    for(int i=1;i<n;i++){
        dp[i][i] = 0;
    }

    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<=n-1;j++){
            int mini = INT_MAX;

            for(int k=i;k<=j-1;k++){
                int steps = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                mini = min(mini,steps);
            }
            dp[i][j] = mini;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return dp[1][n-1];
}
int main() {
	
	vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	
	return 0;
}