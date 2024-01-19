#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    void combinationSum(int i,int k,int sumTillNow, int n, vector<int>& subset, vector<vector<int>>& ans){
        
        if(sumTillNow > n) return;
        if(k==0){
            if(sumTillNow == n){
                ans.push_back(subset);
            }
            return;
        }

        if(i==10) return;

        sumTillNow += i; //pick
        subset.push_back(i);
        combinationSum(i+1,k-1,sumTillNow,n,subset,ans);

        sumTillNow -= i; //not pick
        subset.pop_back();
        combinationSum(i+1,k,sumTillNow,n,subset,ans);

    }

    vector<vector<int>> combinationSumMain(int k,int n){
        vector<vector<int>> ans;
        vector<int> subset;
        combinationSum(1,k,0,n,subset,ans);

        return ans;
    }
};
int main(){
    Solution obj;
    int k = 2;
    int n = 5;
    vector<vector<int>> ans;
    ans = obj.combinationSumMain(k,n);

    cout<<"The unique subsets are "<<endl;
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]";
    return 0;
}