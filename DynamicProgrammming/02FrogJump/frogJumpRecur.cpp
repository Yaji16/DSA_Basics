#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int n,vector<int>& height){
    //base case
    if(n==0){
        return 0;
    }
    int jumpTwo = INT_MAX;
    int  jumpOne = climbingStairs(n-1,height) + abs(height[n]-height[n-1]);
    if(n>1){
        jumpTwo = climbingStairs(n-2,height) + abs(height[n]-height[n-2]);
    }
    return min(jumpOne,jumpTwo);
}
int main(){
    int n = 4;
    vector<int> height = {10,20,30,10};
    cout<<"The minimum energy required "<<climbingStairs(n-1,height);
    return 0;
}