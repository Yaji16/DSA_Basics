#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    void findCombination(int ind, vector<int>& arr, vector<int>& ds, vector<vector<int>> &ans, int target){
        //base condition
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue; //avoid picking duplicate numbers
            if(arr[i]>target) break; // avoid negative target
            ds.push_back(arr[i]); //pick
            findCombination(ind+1,arr,ds,ans,target-arr[i]);
            ds.pop_back(); //not pick
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr,int target){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(),arr.end()); // this ensures the duplicates are next to each other
        //index, arr, currSubseq, ans, target
        findCombination(0, arr, ds, ans, target);

        return ans;
        
    }
};

int main(){
    Solution obj;
    int k = 4;
    vector<int> arr{1,1,1,2,2};
        
    vector<vector<int>> ans = obj.combinationSum2(arr,k);
    cout<<"Combinations of sum "<<k<<" are "<<"\n";
    for(int i = 0; i < ans.size(); i++){
        for(int j=0; j < ans[i].size(); j++){
            cout<< ans[i][j] << " ";
        }
        cout<<"\n";
    }

    
    return 0;
}