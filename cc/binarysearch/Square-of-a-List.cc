#include "solution.hpp"
using namespace std;
// O(NlogN) time | O(1) space
class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        for (int& z : nums) z = z * z;
        sort(nums.begin(), nums.end());
        return nums;
    }
};

vector<int> solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}

// O(N) time and space
vector<int> solve(vector<int>& a) {
    if(a.size() == 0) return {};
    if(a.size() == 1) return {a[0] * a[0]};
    vector<int> res;
    int l,r;
    int id = lower_bound(a.begin(), a.end(), 0) - a.begin();
    l = id-1, r = id;
    if(r >= a.size()) l--,r--;
    if(l < 0) l++, r++;
    while(l >= 0 or r < a.size()){
        if(l >= 0 and (r >= a.size() or a[l] * a[l] <= a[r] * a[r])){
            res.push_back(a[l] * a[l]);
            l--;
        }
        else {
            res.push_back(a[r] * a[r]);
            r++;
        }
    }
    return res;
}

// cleaner
vector<int> solve(vector<int>& a) {
    int l = 0, r = a.size()-1;
    vector<int> res;
    while(l <= r){
        if(a[l] * a[l] >= a[r] * a[r]) {
            res.push_back(a[l] * a[l]);
            l++;
        }
        else {
            res.push_back(a[r] * a[r]);
            r--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
