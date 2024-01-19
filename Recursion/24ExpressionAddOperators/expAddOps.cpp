#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void backtrack(int ind,const string &path, string s, vector<string>& ans, long resSoFar, long prevNum, int target){
        if(ind == s.length()){
            if(resSoFar == target) ans.push_back(path);
            return;
        }
        string numStr;
        long num = 0;
        for(int i=ind;i<s.length();i++){
            if(i>ind && s[ind]=='0') break;
            numStr += s[i];
            num = num*10 + (s[i]-'0');
            if(ind == 0){ //take first number without aadding any operations
                backtrack(i+1,path+numStr,s,ans,num,num,target);
            }else{
                backtrack(i+1,path+"+"+numStr,s,ans,resSoFar+num,num,target);
                backtrack(i+1,path+"-"+numStr,s,ans,resSoFar-num,-num,target);
                backtrack(i+1,path+"*"+numStr,s,ans,resSoFar-prevNum+prevNum*num,prevNum*num,target);
            }
        }
    }
    vector<string> addOperations(string num,int target){
        vector<string> ans;
        string path = "";
        backtrack(0,path,num,ans,0,0,target);
        return ans;
    }
};

int main(){
    Solution obj;
    string s = "123";
    int target = 6;
    vector<string> ans;
    ans = obj.addOperations(s,target);
    for(string s: ans){
        cout<<s<<" ";
    }
}