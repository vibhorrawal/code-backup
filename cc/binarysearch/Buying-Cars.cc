#include "solution.hpp"
using namespace std;
// O(nlogn) time | O(1) space || Greedy
class Solution {
    public:
    int solve(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int count = 0, i = 0;
        while (k >= prices[i] && i < prices.size()) {
            k -= prices[i++];
            count++;
        }
        return count;
    }
};

int solve(vector<int>& prices, int k) {
    return (new Solution())->solve(prices, k);
}

// O(n) time and O(1) space || Quickselect
int solve(vector<int>& a, int k) {
    int l = 0, r = a.size()-1, ans = 0;
    while(l <= r){
        int m = (r+l)/2;
        nth_element(a.begin() + l, a.begin() + m, a.begin() + r + 1);
        int cost = accumulate(a.begin() + l, a.begin() + m + 1, 0);
        if(cost > k){
            r = m - 1;
        }
        else{
            k -= cost;
            ans += m - l + 1;
            l = m + 1;
        }
    }
    return ans;
}
