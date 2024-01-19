#include<bits/stdc++.h>
using namespace std;

//recursive function to convert string to integer 
int check(int i,string s,long ans,int sign){
    //check if the answer is out of range
    if(ans*sign >= INT_MAX) return INT_MAX;
    if(ans*sign <= INT_MIN) return INT_MIN; 

    //Base case: if the input string is processed or if we come across a non number we return ans
    if(i==s.size() || s[i]<'0' || s[i]>'9') return sign*ans;

    //Recursive call to process the next digit in the string
    ans = check(i+1,s,ans*10+(s[i]-'0'),sign); // stoi: current_ans*10 + (current_digit-'0)
    return ans;
}

int myAtoi(string s){
    int i = 0;
    int sign = 1;

    while(i<s.size() && s[i]==' ') i++; //remove leading spaces
    
    //check for sign
    if(s[i]=='-') {sign=-1;i++;} 
    else if(s[i]=='+') i++;

    return check(i,s,0,sign); //call recursive function to convert string to integer
}

int main(){
    string str = "   -42"; //input string
    cout<<"Converting given string to integer ..."<<"\n";
    cout<<myAtoi(str)<<"\n"; //output integer
    return 0;
}