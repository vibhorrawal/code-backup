// O(n^2) time | O(n) space
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        vector<int> lis(nums.size(), 0);
        for(int i =0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        int mx = *max_element(lis.begin(), lis.end());
        return mx >= 2;
    }
};

// O(n) time | O(1) space
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, biggerMin = INT_MAX;
        for(int num : nums){
            if(num <= min){
                min = num;
            }
            else if(num <= biggerMin){
                biggerMin = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
