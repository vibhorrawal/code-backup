class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(!i || nums[i] != nums[i-1]){
                int l = i + 1, r = nums.size() - 1;
                
                while(l < r){
                    if(nums[i] + nums[l] + nums[r] < 0)
                        l++;
                    else if(nums[i] + nums[l] + nums[r] > 0)
                        r--;
                    else{
                        res.push_back({nums[i], nums[l], nums[r]});
                        while(l<r && nums[l] == nums[l+1])
                            l++;
                        l++;
                        while(l<r && nums[r] == nums[r-1]) 
                            r--;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};