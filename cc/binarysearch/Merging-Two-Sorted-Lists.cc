#include "solution.hpp"
using namespace std;
// O(n) time | O(1) space
class Solution {
    public:
    vector<int> solve(vector<int>& lst0, vector<int>& lst1) {
        vector<int> res;
        int i = 0, j = 0;
        lst0.push_back(INT_MAX);
        lst1.push_back(INT_MAX);
        while (res.size() == 0 || res.back() != INT_MAX) {
            if (lst0[i] < lst1[j])
                res.push_back(lst0[i++]);
            else
                res.push_back(lst1[j++]);
        }
        res.pop_back();
        return res;
    }
};

vector<int> solve(vector<int>& lst0, vector<int>& lst1) {
    return (new Solution())->solve(lst0, lst1);
}
