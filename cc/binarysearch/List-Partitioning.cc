// O(N) time | though this is technically creating new strings
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    vector<string> solve(vector<string>& strs) {
        int r = 0, g = 0, b = 0;
        string rr = "red", gg = "green", bb = "blue";
        for (auto s : strs) {
            if (s == rr)
                r++;
            else if (s == gg)
                g++;
            else if (s == bb)
                b++;
            else
                assert(false);
        }
        int j = 0;
        for (int i = 0; i < r; i++) {
            strs[j++] = rr;
        }
        for (int i = 0; i < g; i++) {
            strs[j++] = gg;
        }
        for (int i = 0; i < b; i++) {
            strs[j++] = bb;
        }
        return strs;
    }
};

vector<string> solve(vector<string>& strs) {
    return (new Solution())->solve(strs);
}

// O(1) space
int rearrange(vector<string>& s, int startIdx, string need) {
    for(int i = startIdx; i < s.size(); i++) {
        if(s[i] == need) {
            swap(s[startIdx], s[i]);
            startIdx++;
        }
    }
    return startIdx;
}

vector<string> solve(vector<string>& s) {
    int pos = rearrange(s, 0, "red");
    rearrange(s, pos, "green");
    return s;
}