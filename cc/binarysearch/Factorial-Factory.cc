#include "solution.hpp"
using namespace std;

// recursion O(n) time and space
class Solution {
    public:
    int solve(int n) {
        if (n == 0) return 1;
        return n * solve(n - 1);
    }
};

int solve(int n) {
    return (new Solution())->solve(n);
}
