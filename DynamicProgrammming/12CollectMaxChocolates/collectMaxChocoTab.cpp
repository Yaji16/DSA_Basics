#include<bits/stdc++.h>
using namespace std;

int maximumChocolates(int n,int m,vector<vector<int>>& matrix){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                dp[n-1][j1][j2] = matrix[n-1][j1];
            }else{
                dp[n-1][j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi = INT_MIN;
                for(int di=-1;di<=1;di++){
                    for(int dj=-1;dj<=1;dj++){
                        int ans;
                        if(j1==j2){
                            ans = matrix[i][j1];
                        }else{
                            ans = matrix[i][j1] + matrix[i][j2];
                        }

                        if((j1+di<0) || (j1+di>=m) || ((j2+dj<0) || (j2+dj>=m))){
                            ans += -1e9;
                        }else{
                            ans += dp[i+1][j1+di][j2+dj];
                        }

                        maxi = max(maxi,ans);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
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