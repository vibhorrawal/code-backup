// O(n) time and space
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        set<int> s;
        for (int i : nums) {
            if (s.count(i)) return i;
            s.insert(i);
        }
        return -1;
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}

// O(n) time | O(1) space
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int ind = abs(nums[i]);
            if (nums[ind] < 0) return ind;
            nums[abs(ind)] = -abs(nums[abs(ind)]);
        }
        return -1;
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}

// Floyd Cycle detection algorithm
int solve(vector<int>& a) {
    int tortoize = a[0], hare = a[0];
    do {
        tortoize = a[tortoize];
        hare = a[a[hare]];
    } while(tortoize != hare);

    tortoize = a[0];
    while(tortoize != hare) {
        tortoize = a[tortoize];
        hare = a[hare];
    }
    return hare;
}

// using Sigme(n)
int solve(vector<int>& a) {
    return accumulate(a.begin(), a.end(), 0) - (a.size()) * (a.size()-1) / 2;
}

// XOR property
int solve(vector<int>& a) {
    int ans = 0;
    for(int i = 0; i < a.size(); i++){
        ans = ans ^ a[i];
    }
    for(int i = 0; i < a.size(); i++){
        ans = ans ^ i;
    }
    return ans;
}
