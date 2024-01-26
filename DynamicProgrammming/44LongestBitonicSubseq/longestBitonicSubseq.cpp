#include<bits/stdc++.h>
using namespace std;

int longestBitonicSequence(vector<int> arr,int n){
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);

    for(int i=0;i<n;i++){
        for(int prev_index=0;prev_index<i;prev_index++){
            if(arr[i]>arr[prev_index] && (dp1[prev_index]+1)>dp1[i]){
                dp1[i] = 1 + dp1[prev_index];
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int prev_index=n-1;prev_index>i;prev_index--){
            if(arr[i]>arr[prev_index] && (dp2[prev_index]+1)>dp2[i]){
                dp2[i] = 1 + dp2[prev_index];
            }
        }
    }

    int maxi = -1;
    for(int i=0;i<n;i++){
        int val= dp1[i] + dp2[i] -1;
        if(val>maxi){
            maxi = val;
        }
    }
    return maxi;
}

int main() {
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = arr.size();

    cout << "The length of the longest bitonic subsequence is " << longestBitonicSequence(arr, n) << endl;

    return 0;
}