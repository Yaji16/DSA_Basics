#include<bits/stdc++.h>
using namespace std;

int fibonacciTab(int n){
    
    //base case
    int prev2 = 0;
    int prev1 = 1;
    for(int i=2;i<=n;i++){
        int cur = prev2+prev1;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
int main(){
    int n = 6;
    cout<<"The "<<n<<"th fibonacci number is "<<fibonacciTab(n);
    return 0;
}