class Solution {
    int recurBinSearch(vector<int>& nums, int l, int r, int target){
        if(l > r)
            return -1;
        
        int mid = (l + r) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target)
            return recurBinSearch(nums, l, mid-1, target);
        else
            return recurBinSearch(nums, mid+1, r, target);
    }
public:
    int search(vector<int>& nums, int target) {
        // return recurBinSearch(nums, 0, nums.size()-1, target);
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r){
            mid = (l + r) /2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
