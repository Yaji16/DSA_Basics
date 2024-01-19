#include<bits/stdc++.h>
using namespace std;

//if the numbers are big we need to use modulo to optimize
double recurPower(double x,int n){ //using binary exponentiation, the function will be called Log N times as we divide the power by 2 each time
    if(n==0) return 1;
    else if(n%2==0){
        return recurPower((x*x),n/2);
    }else{
        double ans = (recurPower((x*x),(n-1)/2));
        return x*ans;
    }
}

double power(int x,int n){
    //need to handle negative power by doing 1/(x^n)
    bool neg = false;
    if(n<0){ neg= true; n=-n;}
    if(neg){
        return (double)(1.00/(recurPower(x,n)));
    }
    return (double)recurPower(x,n,mod);
}

int main(){
    int x = 2, n = -3;
    cout<<x<<" power "<<n<<" is : ";
    cout<<power(x,n);
    return 0;
}