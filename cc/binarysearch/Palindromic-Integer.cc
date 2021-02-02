#include "solution.hpp"
using namespace std;

class Solution {
    public:
    bool solve(int num) {
        string s = to_string(num);
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
};

bool solve(int num) {
    return (new Solution())->solve(num);
}

bool solve(int n) {
    long upper = 1;
    while(upper <= n) upper *= 10;
    upper /= 10;
    while(n){
        int u = n / upper, l = n % 10;
        if(u != l) return false;
        n = n % upper;
        n /= 10;
        upper /= 100;
    }
    return true;
}
