#include<bits/stdc++.h>
using namespace std;

stack<int> st;

void insert(stack<int>& s,int v){
    if(s.empty() || s.top()>v){ // ascending, for descending use s.top()<=v
        s.push(v);
        return;
    }
    int t = s.top();
    s.pop();
    insert(s,v);
    s.push(t);
    return;
}
void recurSort(stack<int>& s){
    if(s.size()==1) return;
    int temp = s.top();
    s.pop();
    recurSort(s);
    insert(s,temp);
    return;
}

int main(){
    stack<int> arr;
    arr.push(7);
    arr.push(18);
    arr.push(2);
    arr.push(4);
    arr.push(55);
    arr.push(13);
    arr.push(24);
    
    cout<<"Sorting the stack using recursion...";
    recurSort(arr);
    while(!arr.empty()){
        cout<<arr.top()<<" ";
        arr.pop();
    }
    return 0;
}