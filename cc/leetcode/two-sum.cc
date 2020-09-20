class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end())
                return {i, mp[nums[i]]};
             mp[target - nums[i]] = i;
        }
        return {};
    }
    
};

//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        pair<int,int> ap[n];
        for(int i = 0;i < n; i++) ap[i] = {nums[i],i};
        sort(ap, ap+n);
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(ap[i].first + ap[j].first == target)
                return {ap[i].second, ap[j].second};
            else if(ap[i].first + ap[j].first > target)
                j--;
            else
                i++;
        }
        return {};
    }
};
