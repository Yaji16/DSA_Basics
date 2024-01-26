#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str) {
    int n = str.size();
    // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
    vector<int> dp(n+1,0);

    for(int i=n-1;i>=0;i--){
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,str)){
                int cost = 1 + dp[j+1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }
    return dp[0]-1;
}

int main() {
    string str = "BABABCBADCEDE";
    int partitions = palindromePartitioning(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}
