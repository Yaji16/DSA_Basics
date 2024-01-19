#include<bits/stdc++.h>
using namespace std;

bool searchNext(vector<vector<char>> board,string word,int i,int j,int index,int m,int n){
    if(index == word.length()){
        return true;
    }
    if(i<0 || j<0 || i==m || j==n || board[i][j]!=word[index] || board[i][j]=='!'){
        return false;
    }
    char c = board[i][j];
    board[i][j] = '!';

    bool top = searchNext(board,word,i-1,j,index+1,m,n);
    bool right = searchNext(board,word,i,j+1,index+1,m,n);
    bool bottom = searchNext(board,word,i+1,j,index+1,m,n);
    bool left = searchNext(board,word,i,j-1,index+1,m,n);

    board[i][j] = c;
    
    return top||right||bottom||left;

}

bool exist(vector<vector<char>> board, string word){
    int m = board.size();
    int n = board[0].size();

    int index = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == word[index]){
                if(searchNext(board,word,i,j,index,m,n)) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board {{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};

    string word = "ABCCED";

    bool res = exist(board, word);
    if(res==1)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}