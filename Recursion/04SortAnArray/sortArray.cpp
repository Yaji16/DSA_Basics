#include <bits/stdc++.h>
using namespace std;

// we need to break down the array into smaller inputs and then place it in the right position
// array of size 1 is always sorted

void insert(vector<int>& arr,int v){
    if(arr.size()==0 || arr[arr.size()-1]<=v) { // val is greater than last val
        arr.push_back(v); // directly insert it
        return;
    }
    int val = arr[arr.size()-1]; // remove the greater value
    arr.pop_back();
    insert(arr,v); // insert the current value
    arr.push_back(val); // finally insert the greater value at the end of the arrays
    return;
}
void recurSort(vector<int> &arr){
    if(arr.size() == 1) return; //already sorted - base case
    int temp = arr[arr.size()-1]; // get the last element
    arr.pop_back();
    recurSort(arr); // sort the rest of the array
    insert(arr,temp); // insert the element in the correct position
}


int main(){
    vector<int> arr;
    arr.push_back(7);
    arr.push_back(18);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(55);
    arr.push_back(13);
    arr.push_back(24);
    
    int n = arr.size();
    cout<<"Sorting the array using recursion...";
    recurSort(arr);
    for(int a: arr){
        cout<<a<<" ";
    }
    return 0;
}