#include<bits/stdc++.h>
using namespace std;

int fibonacciRecur(int n){
    //base case
    if(n<=1){
        return n;
    }
    return fibonacciRecur(n-1)+fibonacciRecur(n-2);
}
int main(){
    int n = 6;
    cout<<"The "<<n<<"th fibonacci number is "<<fibonacciRecur(n);
    return 0;
}