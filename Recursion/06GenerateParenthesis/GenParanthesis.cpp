#include<bits/stdc++.h>
using namespace std;

void generate(vector<string>& ans,string str,int open,int close,int max){
    if(str.length()==max*2){ //base condition
        ans.push_back(str);
        return;
    }
    if(open < max){
        generate(ans,str+"(",open+1,close,max);
    }
    if(close<open){
        generate(ans,str+")",open,close+1,max);
    }
}

void generateAllParenthesis(int n){
    vector<string> ans;
    generate(ans,"",0,0,n);
    for(string s: ans){
        cout<<s<<" ";
    }
    cout<<"\n";
}
int main(){
    int N = 2;
    int arr[N];
    cout<<"Generating all the "<<N<<" pair parenthesis strings..."<<"\n";
    generateAllParenthesis(N);
    return 0;
}