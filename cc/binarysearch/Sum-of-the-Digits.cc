#include "solution.hpp"
using namespace std;
// O(logN) time | O(1) space
class Solution {
    public:
    int solve(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
};


int solve(int num) {
    return (new Solution())->solve(num);
}

// cleaner
int solve(int num) {
    if(num < 10) return num;
    return num % 10 + solve(num / 10);
}
