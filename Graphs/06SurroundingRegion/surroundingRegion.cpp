#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void dfs(int row, int col, vector<vector<int>> &vis, 
    vector<vector<char>> &mat, int delrow[], int delcol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat,delrow,delcol);
            }
        }
    }
    public:
    vector<vector<char>> fill(int n,int m,vector<vector<char>> mat){
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        vector<vector<int>> vis(n, vector<int>(m,0)); 

        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0,j,vis,mat,delrow,delcol);
            }
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1,j,vis,mat,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i,0,vis,mat,delrow,delcol);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i,m-1,vis,mat,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

int main(){
    
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    
    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}