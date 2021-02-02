// O(n) time and space
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& a) {
        vector<int> dp(60);
        int ans = 0;
        for(int x : a) {
            x %= 60;
            if(x == 0){
                ans += dp[0];
            }
            else{
                ans += dp[60-x];
            }
            dp[x]++;
        }
        return ans;
    }
};
