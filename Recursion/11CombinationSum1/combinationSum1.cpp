#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    void findCombination(int i, vector<int>& arr, vector<int>& ds, vector<vector<int>> &ans, int target){
        //base condition
        if(i==arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        //pick up an element
        if(arr[i] <= target){
            ds.push_back(arr[i]);
            findCombination(i,arr,ds,ans,target-arr[i]);
            ds.pop_back();
        }
        //not pick the element
        findCombination(i+1,arr,ds,ans,target);

    }

    vector<vector<int>> combinationSum(vector<int>& arr,int target){
        vector<vector<int>> ans;
        vector<int> ds;
        //index, arr, currSubseq, ans, target
        findCombination(0, arr, ds, ans, target);

        return ans;
        
    }
};

int main(){
    Solution obj;
    int k = 7;
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(7);
    
    vector<vector<int>> ans = obj.combinationSum(arr,k);
    cout<<"Combinations of sum "<<k<<" are "<<"\n";
    for(int i = 0; i < ans.size(); i++){
        for(int j=0; j < ans[i].size(); j++){
            cout<< ans[i][j] << " ";
        }
        cout<<"\n";
    }

    
    return 0;
}