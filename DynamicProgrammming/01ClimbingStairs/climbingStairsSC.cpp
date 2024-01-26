#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int n){

    vector<int> dp(n+1);
    //base case
    int prev2 = 1;
    int prev1 = 1;
    
    for(int i=2;i<=n;i++){
        int cur = prev1+prev2;
        prev2=prev1;
        prev1=cur;
    }
    return prev1;
}
int main(){
    int n = 4;
    
    cout<<"The no: of ways to climb "<<n<<" stairs is "<<climbingStairs(n);
    return 0;
}