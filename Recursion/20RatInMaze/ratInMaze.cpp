#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void findPathHelper(int r, int c, vector<vector<int>>& m, int  n, vector<string> &ans, string path, vector<vector<int>>& visited){
        // reached destination- Base case
        if(r==n-1 && c==n-1){
            ans.push_back(path);
            return;
        }

        //down
        if(r+1<n && !visited[r+1][c] && m[r+1][c]==1){
            visited[r][c] = 1;
            findPathHelper(r+1,c,m,n,ans,path+'D',visited);
            visited[r][c] = 0;
        }

        //left
        if(c-1>=0 && !visited[r][c-1] && m[r][c-1]==1){
            visited[r][c] = 1;
            findPathHelper(r,c-1,m,n,ans,path+'L',visited);
            visited[r][c] = 0;
        }

        //right
        if(c+1<n && !visited[r][c+1] && m[r][c+1]==1){
            visited[r][c] = 1;
            findPathHelper(r,c+1,m,n,ans,path+'R',visited);
            visited[r][c] = 0;
        }

        //up
        if(r-1>=0 && !visited[r-1][c] && m[r-1][c]==1){
            visited[r][c] = 1;
            findPathHelper(r-1,c,m,n,ans,path+'U',visited);
            visited[r][c] = 0;
        }
    }

    public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
      vector<string> ans;
      vector<vector<int>> visited(n,vector<int> (n,0));
      if(m[0][0]==0) return ans; //return empty ans
      findPathHelper(0, 0, m, n, ans, " ", visited);
      return ans;
    }
};

int main() {
  int n = 4; // we are taking 4*4 grid
  Solution obj;
  vector <vector<int>> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
  vector<string> ans = obj.findPath(m,n);
  if(ans.size()==0) cout<<-1;
  else{
    cout<<"The paths are: "<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<< ans[i] << " ";
    }
    cout<<"\n";
  }
  return 0;
}