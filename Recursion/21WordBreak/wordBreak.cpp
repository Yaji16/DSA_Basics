#include<bits/stdc++.h>
using namespace std;

bool canBreak(int ind,string s,unordered_set<string> wordDict){
    if(ind == s.size()) return true;
    string sub="";
    
    for(int i=ind;i<s.size();i++){
        sub += s[i];
        
        if(wordDict.count(sub) && canBreak(i+1,s,wordDict)) { return true;}
    }
    return false;
}
bool wordBreak(string s,unordered_set<string> wordDict){
    return canBreak(0,s,wordDict);
}
int main(){
    string s= "catsandog";
    unordered_set<string> wordDict;

    wordDict.insert("cats");
    wordDict.insert("dog");
    wordDict.insert("sand");
    wordDict.insert("and");
    wordDict.insert("cat");

    if(wordBreak(s,wordDict)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}