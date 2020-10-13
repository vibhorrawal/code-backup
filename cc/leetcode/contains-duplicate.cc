// O(n) time | O(n) space
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> contains;
        for(int n: nums){
            if(contains.count(n))
                return true;
            contains.insert(n);
        }
        return false;
    }
};

// O(nlogn) time | O(1) space
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == nums[i+1])
                return true;
        return false;
    }
};
