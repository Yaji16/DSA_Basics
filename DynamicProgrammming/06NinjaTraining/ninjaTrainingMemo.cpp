#include<bits/stdc++.h>
using namespace std;

//Two parameters are varying -the day is changing and also the last activity performed (2D)
int solve(int day,int last, vector<vector<int>>& points, vector<vector<int>>& dp){
    //day is 0 - max points on that day (exclude prev day points): Base case
    if(dp[day][last] != -1) return dp[day][last];
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    //get max points other than the activity done yesterday
    int maxi = 0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            int activity = points[day][i] + solve(day-1,i,points,dp); //activity i picked for the day, find points for rest of the days
            maxi = max(maxi,activity); //keep track of max points obtaine so far
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(int n,vector<vector<int>>& points){
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return solve(n-1,3,points,dp); //3 indicated no activity done before
}
int main() {
  // Define the points matrix
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};

  int n = points.size();  // Get the number of days
  // Call the ninjaTraining function to find the maximum points and print the result
  cout << ninjaTraining(n, points);
}