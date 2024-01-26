#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int n){
    //base case
    if(n<=1){
        return 1;
    }
    return climbingStairs(n-1)+climbingStairs(n-2);
}
int main(){
    int n = 4;
    cout<<"The no: of ways to climb "<<n<<" stairs is "<<climbingStairs(n);
    return 0;
}