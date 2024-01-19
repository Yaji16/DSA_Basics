#include<bits/stdc++.h>
using namespace std;

void generateAllBinaryStrings(int n,int arr[],int i){
    if(i==n){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<"\n";
        return;
    }
    arr[i] = 0;
    generateAllBinaryStrings(n,arr,i+1);

    arr[i] = 1;
    generateAllBinaryStrings(n,arr,i+1);
}
int main(){
    int N = 2;
    int arr[N];
    cout<<"Generating all the "<<N<<" bit binary strings..."<<"\n";
    generateAllBinaryStrings(N,arr,0);
    return 0;
}