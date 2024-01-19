#include<bits/stdc++.h>
using namespace std;


class Solution{
    public: 

    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void palindromePartHelper(int ind,string str,vector<string>& ds,vector<vector<string>>& ans){

        if(ind == str.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=ind; i<str.size(); i++){ //try to partition at every index starting from ind

            if(isPalindrome(str,ind,i)){ // valid palindrome partition?
                ds.push_back(str.substr(ind,i-ind+1)); //push the palindrome
                
                palindromePartHelper(ind+1,str,ds,ans); //check for the rest of the string
                
                ds.pop_back(); //back tracking
            }

        }
    }
    vector<vector<string>> palindromePart(string str){
        vector<vector<string>> ans;
        vector<string> ds;
        int ind = 0;
        palindromePartHelper(ind,str,ds,ans);
        return ans;
    }
};

int main(){
    Solution obj;
    string str = "aab";
    vector<vector<string>> ans;
    ans = obj.palindromePart(str);

    cout<<"The palindrom partitions are: "<<"\n";
    for(int i=0;i<ans.size();i++){
        for(string s: ans[i]){
            cout<< s << " ";
        }
        cout<<"\n";
    }
    
    return 0;
}