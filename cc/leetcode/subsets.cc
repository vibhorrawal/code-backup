//remove one by one and insert one by one
class Solution {
    vector<vector<int>> res;
    vector<int> nums;
    int k;
    
    void util(int first, vector<int> curr){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        
        for(int i = first; i < nums.size(); i++){
            curr.push_back(nums[i]);
            util(i+1, curr);
            curr.erase(--curr.end());
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        res.clear();
        nums = arr;
        vector<int> temp;
        
        for(k = 0;k <= nums.size(); k++)
            util(0,temp);
        return res;
    }
};

// bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(int bit = 0; bit < pow(2,nums.size()); bit++){
            vector<int> temp;
            for(int i = 0; i < nums.size(); i++){
                if((bit>>i) & 1){
                    temp.push_back(nums[i]);
                }
            }
            res.push_back(temp);
        }
        
        return res;
    }
};

// add to prev sets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(auto num: nums){
            vector<vector<int>> temp(res.begin(), res.end());
            for(int i = 0; i < temp.size(); i++){
                temp[i].push_back(num);
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};

// recursively generate
class Solution {
    vector<vector<int>> util(vector<int>& nums, int pos){
        if(pos < 0)
            return {{}};
        
        int ele = nums[pos];
        vector<vector<int>> subset = util(nums, pos-1);
        int n = subset.size();
        
        for(int i = 0; i < n; i++){
            vector<int> temp (subset[i].begin(), subset[i].end());
            temp.push_back(ele);
            subset.push_back(temp);
        }
        return subset;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return util(nums, nums.size()-1);
    }
};
