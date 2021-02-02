#include<bits/stdc++.h>
using namespace std;

// recursive
int knapsack(vector<int> &weight, vector<int> &value, int capacity, int n){
        if(n == 0 or capacity == 0)
            return 0;

        if(weight[n-1] >= capacity)
            return max(value[n-1] + knapsack(weight, value, capacity - weight[n-1], n-1),
                      knapsack(weight, value, capacity, n-1));

        return knapsack(weight, value, capacity, n-1);
}

// iterative bottom up DP
int _01knapsack(vector<int> &weight, vector<int> &value, int W) {
    // fill the back upto W capacity
    int n = value.size();
    vector<vector<int>> dp(n + 1, vector<int> (W + 1, 0));

    // initialisation
    for(int i = 0; i < n + 1; i++) dp[i][0] = 0;
    for(int j = 0; j < W + 1; j++) dp[0][j] = 0;

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < W + 1; j++){
          if(j >= weight[i-1])
              dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j - weight[i-1]]);
          else
              dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int unbound_knapsack(vector<int> &weight, vector<int> &value, int W) {
    // fill the back upto W capacity
    int n = value.size();
    vector<vector<int>> dp(n + 1, vector<int> (W + 1, 0));

    // initialisation
    for(int i = 0; i < n + 1; i++) dp[i][0] = 0;
    for(int j = 0; j < W + 1; j++) dp[0][j] = 0;

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < W + 1; j++){
          if(j >= weight[i-1])
              dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i][j - weight[i-1]]);
          else
              dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int32_t main(int argc, char const *argv[]){

  return 0;
}
