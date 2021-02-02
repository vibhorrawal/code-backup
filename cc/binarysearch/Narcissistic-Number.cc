#include "solution.hpp"
using namespace std;
// O(n) time and space
class Solution {
    vector<int> digits(int n) {
        vector<int> res;
        while (n) {
            int s = n % 10;
            res.push_back(s);
            n /= 10;
        }
        return res;
    }

    public:
    bool solve(int n) {
        int dig = ceil(log10(n));
        vector<int> v = digits(n);
        int sum = 0;
        for (int i : v) sum += pow(i, dig);
        return sum == n;
    }
};

bool solve(int n) {
    return (new Solution())->solve(n);
}
