#include<bits/stdc++.h>
using namespace std;
#define ll long long

int p = (1e9+7);
ll power(ll x, ll y){
    ll res = 1;
    x = x%p;
    if(x==0) return 0;

    while(y>0){
        if(y&1) res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}
// even positions: even digits - 0,2,4,6,8 (5)
// odd positions: prime digits - 2,3,5,7 (4)
int countGoodNumbers(int n){
    int p = 1e9+7;
    ll countOf4s = n/2;
    ll countOf5s = n-countOf4s;
    ll ans = (((power(4ll,countOf4s))%p * (power(5ll,countOf5s))%p)%p);
    return ans;
}

int main(){
    int n = 4;
    int ans = countGoodNumbers(n);
    cout<<"Count of good numbers are: "<< ans;
    return 0;
}