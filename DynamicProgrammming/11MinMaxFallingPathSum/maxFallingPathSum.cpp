#include<bits/stdc++.h>
using namespace std;


int getMaxPathSum(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j=0;j<m;j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){

            int up = matrix[i][j] + dp[i-1][j];

            int leftDiag = matrix[i][j];
            if(j-1>=0){
                leftDiag += dp[i-1][j-1];
            }else{
                leftDiag += -1e9;
            }

            int rightDiag = matrix[i][j];
            if(j+1<m){
                rightDiag += dp[i-1][j+1];
            }else{
                rightDiag += -1e9;
            }

            dp[i][j] = max(up, max(leftDiag,rightDiag));
        }
    }
    int maxi = INT_MIN;
    for(int j=0;j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
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