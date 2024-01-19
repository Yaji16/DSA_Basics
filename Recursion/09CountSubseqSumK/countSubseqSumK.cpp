#include<bits/stdc++.h>
using namespace std;

int countAllSubseqK(int i,vector<int>& arr,int sum,int k){
    if(i==arr.size()){
        if(sum == k){
            return 1;
        }
        return 0;
    }
    sum += arr[i];
    int l = countAllSubseqK(i+1,arr,sum,k);

    sum -= arr[i];
    int r = countAllSubseqK(i+1,arr,sum,k);

    return l+r;
}
int main(){
    int k = 2;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    
    cout<<"Number of the subsequences of sum "<<k<<" is "<<"\n";
    int ans = countAllSubseqK(0, arr, 0, k);
    cout<< ans ;
    return 0;
}