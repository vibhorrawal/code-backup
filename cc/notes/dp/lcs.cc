#include<bits/stdc++.h>
using namespace std;

// recursive
int lcs(string a, int n, string b, int m){
    if(n == 0 or m == 0)
        return 0;

    if(a[n-1] == b[m-1])
        return 1 + lcs(a, n-1, b, m-1);

    return max(lcs(a, n-1, b, m), lcs(a, n, b, m-1));
}

// return the lcs string
string lcs_string(const string &a, const string &b, vector<vector<int>> &dp){
      int i = a.size(), j = b.size();
      string res;
      while(i and j){
          if(a[i-1] == b[j-1]){
                res.push_back(a[i-1]);
                i--,j--;
          }
          else{
              if(dp[i][j-1] > dp[i-1][j])
                  j--;
              else
                  i--;
          }
      }
      reverse(res.begin(), res.end());
      return res;
}
// bottom up DP
int longestCommonSubsequence(string a, string b) {
      int n = a.size(), m = b.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1));

      for(int i = 0; i <= n; i++){
          for(int j = 0; j <= m; j++){
              if(i == 0 || j == 0)
                  dp[i][j] = 0;
              else if(a[i-1] == b[j-1])
                  dp[i][j] = dp[i-1][j-1] + 1;
              else
                  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
      }
      cout<< lcs_string(a,b,dp);
      return dp[n][m];
}


int main(){
  string a = "abcdaf", b = "acbcf";
  longestCommonSubsequence(a,b);
}
