// O(1) total() time | O(N) space
class RangeSum {
    vector<long> pre;
    public:
    RangeSum(vector<int>& nums) {
        int l = 0;
        pre.resize(nums.size());
        pre[0] = 0;
        for(int i = 1; i < nums.size(); i++){
            // l += nums[i-1];
            pre[i] = pre[i-1] + nums[i-1];
        }
        pre.push_back(nums.back() + pre.back());
    }

    int total(int i, int j) {
        return pre[j] - pre[i];
    }
};
