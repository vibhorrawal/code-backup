#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(int n) {
        int count = 1;
        while (n != 1) {
            count++;
            if (n & 1)
                n = 3 * n + 1;
            else
                n /= 2;
        }
        return count;
    }
};

int solve(int n) {
    return (new Solution())->solve(n);
}
