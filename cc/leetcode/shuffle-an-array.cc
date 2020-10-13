// O(n) time | O(1) space shuffle
class Solution {
    vector<int> arr;
    int r(int l, int r){
        int val = rand() % (r - l + 1);
        return l + val;
    }
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(arr.begin(), arr.end());
        int n = ans.size();
        for(int i = 0; i < n; i++){
            int j = r(i,n-1);
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
