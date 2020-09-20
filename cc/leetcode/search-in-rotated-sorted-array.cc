// O(logn) time | O(1) space
class Solution {
    int binarySearch(int start, int end, vector<int>& nums, int target){
        if(start >= end)
            return target == nums[end] ? end : -1;
        int mid = (start + end) /2;
        if(nums[mid] == target)
            return mid;
        
        if(nums[start] <= nums[mid]){
            if(nums[start] <= target && target < nums[mid])
                return binarySearch (start, mid-1, nums, target);
            else
                return binarySearch(mid+1, end, nums, target);
        }
        else{
            if(nums[mid] < target && target <= nums[end])
                return binarySearch(mid+1, end, nums, target);
            else
                return binarySearch(start, mid-1, nums, target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, nums, target);
    }
};
