#include<bits/stdc++.h>
using namespace std;

double recurPower(int x,int n){
    //Base case: when power is 0-answer is 1, and when power is one the ans is x
    if(n==0) return 1;
    if(n==1) return x;
    //each time we multiply x and reduce the power by one - we call this n times
    return x*recurPower(x,n-1);
}

double power(int x,int n){
    //need to handle negative power by doing 1/(x^n)
    bool neg = false;
    if(n<0){ neg= true; n=-n;}
    if(neg){
        return (double)(1.00/(recurPower(x,n)));
    }
    return (double)recurPower(x,n);
}

int main(){
    int x = 2, n = 10;
    cout<<x<<" power "<<n<<" is : ";
    cout<<power(x,n);
    return 0;
}