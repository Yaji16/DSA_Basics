#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void subsetSumHelper(int i,vector<int>& arr,vector<int>& ans,int sum){
        if(i == arr.size()){
            ans.push_back(sum);
            return;
        }
        subsetSumHelper(i+1,arr,ans,sum+arr[i]); //pick
        subsetSumHelper(i+1,arr,ans,sum); //not pick
    }

    vector<int> subsetSum(vector<int>& arr){
        vector<int> ans;
        subsetSumHelper(0,arr,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> arr{5,2,1};
    cout<<"Sum of all the subsets that can be formed from the array are: ";
    vector<int> ans = obj.subsetSum(arr);
    for(int sum: ans){
        cout<<sum<<" ";
    }
    return 0;
}