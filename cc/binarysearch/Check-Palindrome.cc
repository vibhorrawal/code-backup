// O(n) time
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    bool solve(string s) {
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
};

bool solve(string s) {
    return (new Solution())->solve(s);
}
