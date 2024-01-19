#include<bits/stdc++.h>
using namespace std;

void generateAllSubseqK(int i, vector<int>& arr, vector<int>& ds,int k,int sum){
    if(i==arr.size()){
        if(sum == k){
            for(int d: ds) cout<<d<<" ";
            cout<<"\n";
        }
        return;
    }
    ds.push_back(arr[i]);
    sum += arr[i];
    generateAllSubseqK(i+1,arr,ds,k,sum);
    ds.pop_back();
    sum-=arr[i];
    generateAllSubseqK(i+1,arr,ds,k,sum);
}
int main(){
    int k = 2;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    vector<int> ds;
    cout<<"Generating all the subsequences of sum "<<k<<"\n";
    generateAllSubseqK(0, arr, ds, k, 0);
    return 0;
}