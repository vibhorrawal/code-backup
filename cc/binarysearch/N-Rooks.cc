#include "solution.hpp"
using namespace std;

// math O(1) nothing better
class Solution {
    public:
    int solve(int n) {
        if (n == 1) return 1;
        return n * solve(n - 1);
    }
};

int solve(int n) {
    return (new Solution())->solve(n);
}
