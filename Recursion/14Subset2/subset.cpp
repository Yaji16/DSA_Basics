#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void subsetHelper(int ind,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans){
        ans.push_back(ds);

        for(int i=ind;i<arr.size();i++){
            if(i!=ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            subsetHelper(ind+1,arr,ds,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subset(vector<int>& arr){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(),arr.end());
        subsetHelper(0,arr,ds,ans);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1,2,2};
    cout<<"All the subsets that can be formed from the array are: ";
    vector<vector<int>> ans = obj.subset(arr);
    

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
