#include<bits/stdc++.h>
using namespace std;

void generateAllSubseq(int i, string& s, string& str){
    if(i==str.length()){
        cout<<s<<" ";
        return;
    }
    s = s + str[i];
    generateAllSubseq(i+1,s,str);
    s.pop_back();
    generateAllSubseq(i+1,s,str);
}
int main(){
    string s = "312";
    string ans = "";
    cout<<"Generating all the subsequences of the string..."<<"\n";
    generateAllSubseq(0,ans, s);
    return 0;
}