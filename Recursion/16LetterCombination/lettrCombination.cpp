#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void letterCombinationHelper(int i, string digits, string &output, vector<string>& ans, vector<string>& pad){
        if(i == digits.size()){
            ans.push_back(output);
            return;
        }
        string value = pad[digits[i]-'0'];
        for(int k=0;k<value.size();k++){
            output.push_back(value[k]);
            letterCombinationHelper(i+1,digits,output,ans,pad);
            output.pop_back();
        }
    }
    vector<string> letterCombination(string s){
        if(s.length()==0) return {};
        vector<string> pad = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string output;
        letterCombinationHelper(0,s,output,ans,pad);
        return ans;
    }
};

int main(){
    Solution obj;
    string digits = "29";
    vector<string> ans;
    cout<<"The letter combinations are: "<<"\n";
    ans = obj.letterCombination(digits);

    for(string s: ans){
        cout<<s<<" ";
    }
    return 0;
}