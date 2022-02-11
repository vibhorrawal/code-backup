#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        return solve(n - 1) + solve(n - 2);
    }
};

int solve(int n) {
    return (new Solution())->solve(n);
}

// not needed as N is small, but can save 2^N in above function
// O(N) space
int solve(int n) {
    vector<int> dp(n+1);
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

// not needed but i like this also: https://binarysearch.com/problems/Nth-Fibonacci-Number/solutions/4580884 
// O(LogN) using matrix expn