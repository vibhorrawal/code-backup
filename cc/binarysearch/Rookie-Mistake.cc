#include "solution.hpp"
using namespace std;

class Solution {
    public:
    bool solve(string s) {
        int l = 0, r;
        while (s[l] != 'R') l++;
        r = l;
        l--;
        while (l >= 0 && s[l] != 'B') l--;
        if (l == -1) return true;
        while (r < s.size() && s[r] != 'B') r++;
        return r == s.size();
    }
};

bool solve(string s) {
    return (new Solution())->solve(s);
}

// alternate
bool solve(string s) {
    for(int rep = 0; rep < 2; rep++) {
        int i = 0;
        while(i < s.size() and s[i] == '.' or s[i] == 'R') {
            if(s[i] == 'R') return true;
            i++;
        }
        reverse(s.begin(), s.end());
    }
    return false;
}

// alternate
bool solve(string s) {
    int i = s.find('R');
    return s.substr(0, i).find('B') == -1 or s.substr(i).find('B') == -1;
}
