// O(NlgN) time | O(1) space
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    bool solve(string s0, string s1) {
        sort(s0.begin(), s0.end());
        sort(s1.begin(), s1.end());
        return s0 == s1;
    }
};

bool solve(string s0, string s1) {
    return (new Solution())->solve(s0, s1);
}


// O(N) time and O(1) space
bool solve(string s0, string s1) {
    vector<int> v0(512), v1(512);
    for(char c : s0) v0[c]++;
    for(char c : s1) v1[c]++;
    return v0 == v1;
}
