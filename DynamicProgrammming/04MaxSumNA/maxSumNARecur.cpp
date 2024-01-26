#include<bits/stdc++.h>
using namespace std;

int maxSum(int ind,vector<int>& arr){
    //base case
    if(ind==0) return arr[ind];
    if(ind<0) return 0;

    int pick = arr[ind] + maxSum(ind-2,arr);
    int notPick = 0 + maxSum(ind-1,arr);

    return max(pick,notPick);
}
int solve(int n, vector<int>& arr) {
    return maxSum(n - 1, arr); 
}
int main(){
    int n = 4;
    vector<int> arr = {2,1,4,9};
    cout<<"The maximum sum from non adjacent elements "<<solve(n,arr);
    return 0;
}