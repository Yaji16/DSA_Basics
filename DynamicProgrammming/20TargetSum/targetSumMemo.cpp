#include<bits/stdc++.h>
using namespace std;

//the numbers are changing, the target sum is changing
int targetSumUtil(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(ind == 0){
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || arr[0]==target) return 1;
        return 0;
    }
    
    int notTaken = targetSumUtil(ind-1,target,arr,dp);
    int taken = 0;
    if(arr[ind]<=target){
        taken = targetSumUtil(ind-1,target-arr[ind],arr,dp);
    }
    
    return taken+notTaken;

}
int targetSum(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for(int i=0;i<n;i++){
        totSum += arr[i];
    }
    // s1 + s2 = target
    // s1 - s2 = totSum
    // s2 = (totSum - target)/2

    if(totSum - target < 0) return 0;
    if((totSum - target)%2) return 0;
    int k = (totSum-target)/2;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return targetSumUtil(n-1,k,arr,dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    int target = 3;
                     
    int n = arr.size();
    cout << "The number of ways found is " << targetSum(n, target, arr) << endl;
    
    return 0; // Return 0 to indicate successful program execution
}