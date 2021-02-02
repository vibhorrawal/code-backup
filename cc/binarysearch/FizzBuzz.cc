#include "solution.hpp"
using namespace std;

// O(n) time | space
class Solution {
    public:
    vector<string> solve(int n) {
        string fizz = "Fizz", buzz = "Buzz";
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            string temp = "";
            if (i % 3 == 0) temp += fizz;
            if (i % 5 == 0) temp += buzz;
            if (temp.size() == 0) temp += to_string(i);
            res.push_back(temp);
        }
        return res;
    }
};

vector<string> solve(int n) {
    return (new Solution())->solve(n);
}
