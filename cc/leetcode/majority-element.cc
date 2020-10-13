// O(n) time | O(1) space
// Boyer Moore Voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, elem = nums[0];
        for(int num : nums){
            if(num == elem) count++;
            else count--;
            if(count == 0) elem = num, count = 1;
        }
        return elem;
    }
};
