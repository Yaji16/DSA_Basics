#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& v){
    if(v.empty()) return 0;
    int m = v.size(), n = v[0].size();

    queue<pair<int,int>> rotten;

    int tot = 0;//total number of oranges
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[i][j] != 0) tot++;
            if(v[i][j] == 2) rotten.push({i,j});
        }
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int cnt = 0, days = 0;
    while(!rotten.empty()){
        int k = rotten.size(); //count of rotten oranges
        cnt += k;
        while(k--){
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx<0 || ny<0 || nx>=m || ny>=n || v[nx][ny] != 1){
                    continue;
                }

                v[nx][ny] = 2; //rotten the orange
                rotten.push({nx,ny});
            }
        }
        if(!rotten.empty()) days++;
    }
    return tot == cnt ? days : -1; //if all the oranges are rotten return the days else -1
}
int main()
{
    vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,2} } ;
    int rotting = orangesRotting(v);
    cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
}
    