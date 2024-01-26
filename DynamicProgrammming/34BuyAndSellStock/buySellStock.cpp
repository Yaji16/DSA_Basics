#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int>& arr){
    int maxProfit = 0;
    int mini = arr[0];
    for(int i=1;i<arr.size();i++){

        int curProf = arr[i] - mini;
        maxProfit = max(maxProfit, curProf);
        mini = min(mini,arr[i]);
        
    }
    return maxProfit;
}
int main() {

  vector<int> Arr  ={7,1,5,3,6,4};

  cout<<"The maximum profit by selling the stock is "<<maximumProfit(Arr);
}