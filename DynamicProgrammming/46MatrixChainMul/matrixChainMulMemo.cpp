#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int i,int j,vector<vector<int>>& dp){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    for(int k=i;k<=j-1;k++){
        int steps = solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini,steps);
    }
    return mini;
}

int matrixMultiplication(vector<int>& arr,int n){
    int i = 1;
    int j = n-1;
    vector<vector<int>> dp(n,vector<int> (n,-1));
    return solve(arr,i,j,dp);
}
int main() {
	
	vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	
	return 0;
}