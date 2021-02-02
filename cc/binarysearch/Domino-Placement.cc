#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(int n, int m) {
        if (m % 2 == 0) swap(n, m);
        int count = 0;
        if (n % 2 == 0) {
            count = n / 2;
            count *= m;
        } else {
            if (n > m) swap(n, m);
            count = n;
            count *= m / 2;
            count += n / 2;
        }

        return count;
    }
};

int solve(int n, int m) {
    return (new Solution())->solve(n, m);
}
