#include<bits/stdc++.h>
using namespace std;

//Two parameters are varying -the day is changing and also the last activity performed (2D)
int ninjaTraining(int n, vector<vector<int>>& points){
    vector<vector<int>> dp(n, vector<int>(4, 0));
    //day is 0 - max points on that day (exclude prev day points): Base case
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][1],points[0][0]);
    dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));

    //get max points other than the activity done yesterday
    
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last] = 0;
            for(int task = 0;task<=2;task++){
                if(task!=last){
                    int activity = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    return dp[n-1][3];
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