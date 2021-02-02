#include "solution.hpp"
using namespace std;
// O(N) time and space
class Solution {
    public:
    int solve(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) s.insert(i);
        return s.size();
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}

// O(N) time | O(1) space
int solve(vector<int>& a) {
    int ans = not a.empty();
    for(int i = 1; i < a.size(); i++)
        if(a[i-1] != a[i]) ans++;
    return ans;
}

// STL
int solve(vector<int>& a) {
    return unique(a.begin(), a.end()) - a.begin();
}

// O(k logN) time
int solve(vector<int>& a) {
    int cnt = 0, i = 0;
    while(i < a.size()){
        i = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
        cnt++;
    }
    return cnt;
}

// coded BS
int upper(vector<int> &a, int i){
    int val = a[i];
    int l = i, r = a.size()-1;
    int ans = l;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == val) ans = max(ans, m);
        if(a[m] > val) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans;
}
int solve(vector<int>& a) {
    int cnt = 0, i = 0;
    while(i < a.size()){
        i = upper(a, i) + 1;
        cnt++;
    }
    return cnt;
}
