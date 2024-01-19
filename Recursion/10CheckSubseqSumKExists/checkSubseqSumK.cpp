#include<bits/stdc++.h>
using namespace std;

int checkSubseqK(int i,vector<int>& arr,int sum,int k){
    if(i==arr.size()){
        if(sum == k){
            return true;
        }
        return false;
    }
    sum += arr[i];
    if(checkSubseqK(i+1,arr,sum,k)) return true;

    sum -= arr[i];
    if(checkSubseqK(i+1,arr,sum,k)) return true;

    return false;
}
int main(){
    int k = 5;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    
    cout<<"Is there a subsequence of sum "<<k<<" ? "<<"\n";
    bool ans = checkSubseqK(0, arr, 0, k);
    cout<< ans ;
    return 0;
}