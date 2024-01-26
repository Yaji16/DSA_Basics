#include<bits/stdc++.h>
using namespace std;

int maxChocoSolve(int i,int j1,int j2, vector<vector<int>>& matrix,int n,int m,vector<vector<vector<int>>>& dp){

    //Base case:
    if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;
    if(i==n-1){
        if(j1==j2){ return matrix[i][j1];}
        else{
            return matrix[i][j1] + matrix[i][j2];
        }
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = INT_MIN;
    for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
            int ans = matrix[i][j1];
            if(j1==j2){
                ans += maxChocoSolve(i+1,j1+di,j2+dj,matrix,n,m,dp);
            }else{
                ans = ans + matrix[i][j2] + maxChocoSolve(i+1,j1+di,j2+dj,matrix,n,m,dp);
            }
            maxi = max(maxi,ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n,int m,vector<vector<int>>& matrix){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return maxChocoSolve(0,0,m-1,matrix,n,m,dp);
}
int main() {
    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates(n, m, matrix);

    return 0;
}