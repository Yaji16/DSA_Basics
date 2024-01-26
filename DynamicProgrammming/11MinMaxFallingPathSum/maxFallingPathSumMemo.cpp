#include<bits/stdc++.h>
using namespace std;

int getMaxPathSumUtil(int i,int j,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    
    if(j<0 || j>=m){
        return INT_MIN;
    }
    if(i==0) return matrix[i][j];
    if(dp[i][j] != - 1) return dp[i][j];
    
    int up = matrix[i][j] + getMaxPathSumUtil(i-1,j,m,matrix,dp);
    int leftDiag = matrix[i][j] + getMaxPathSumUtil(i-1,j-1,m,matrix,dp);
    int rightDiag = matrix[i][j] + getMaxPathSumUtil(i-1,j+1,m,matrix,dp);

    return dp[i][j] = max(up, max(leftDiag,rightDiag));
}
int getMaxPathSum(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = INT_MIN;
    for(int j=0;j<m;j++){
        int sum = getMaxPathSumUtil(n-1,j,m,matrix,dp);
        maxi = max(maxi,sum);
    }
    return maxi;
}
int main() {
    // Define the matrix as a 2D vector
    vector<vector<int>> matrix{{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
    
    // Call the getMaxPathSum function and print the result
    cout << getMaxPathSum(matrix);

    return 0;
}