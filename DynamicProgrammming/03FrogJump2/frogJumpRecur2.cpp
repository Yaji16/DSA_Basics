#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int index,int k,vector<int>& height){
    //base case
    if(index==0){
        return 0;
    }
    int minSteps = INT_MAX;
    for(int i=1;i<=k;i++){
        if(index-i>=0){
            int jump = climbingStairs(index-i,k,height) + abs(height[index-i]-height[index]);
            minSteps = min(minSteps,jump);
        }
    }
    return minSteps;
}
int main(){
    int n = 4;
    int k = 2;
    vector<int> height = {10,20,30,10};
    cout<<"The minimum energy required "<<climbingStairs(n-1,k,height);
    return 0;
}