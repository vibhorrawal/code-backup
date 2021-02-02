O(n * S) time and space
// tle and mle on big S
class Solution {
public:
    int findTargetSumWays(vector<int>& a, int S) {
        // Sa + Sb = Sn
        // Sa - Sb = S
        // to count # of Sa -> (Sn + S) / 2
        int total = accumulate(a.begin(), a.end(), 0);
        if(S > total or S < -total)
          return 0;
        int target = (total + S);
        if(target % 2) return 0;
        target /= 2;
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int> (target + 1));
        for(int j = 0; j < target + 1; j++) dp[0][j] = 0;
        for(int i = 0; i < n + 1; i++) dp[i][0] = 1;

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < target + 1; j++){
                if(a[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - a[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};

// O(N * S) time and space
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int,int> ans;
        ans[0] = 1;
        for(int n : nums){
            unordered_map<int,int> temp;
            for(auto [sum, count] : ans){
                temp[sum - n] += count;
                temp[sum + n] += count;
            }
            ans = temp;
        }
        return ans[S];
    }
};

// as given inp also had zeroes and calculating for out of bounds, the first code also works
class Solution {
public:
    int findTargetSumWays(vector<int>& a, int S) {
        // Sa + Sb = Sn
        // Sa - Sb = S
        // to count # of Sa -> (Sn + S) / 2
        int total = accumulate(a.begin(), a.end(), 0);
        if(S > total or S < -total)
          return 0;
        int target = (total + S);
        if(target % 2) return 0;
        target /= 2;
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int> (target + 1));
        for(int j = 0; j < target + 1; j++) dp[0][j] = 0;
        for(int i = 0; i < n + 1; i++) dp[i][0] = 1;

        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < target + 1; j++){
                if(a[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - a[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= target; j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        return dp[n][target];
    }
};
