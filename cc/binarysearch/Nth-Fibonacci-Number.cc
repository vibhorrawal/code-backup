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
