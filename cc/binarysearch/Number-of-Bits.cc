#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(int n) {
        return __builtin_popcount(n);
    }
};

int solve(int n) {
    return (new Solution())->solve(n);
}

// Brian Kernighan's algorithm
int solve(int n) {
    int ans = 0;
    while(n){
        n = n & (n-1);
        ans++;
    }
    return ans;
}
