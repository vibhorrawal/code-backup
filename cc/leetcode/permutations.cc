class Solution {
    vector<vector<int>> res;
    void util(vector<int> nums, int pos){
        if(pos == nums.size()){
           res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            swap(nums[i],nums[pos]);
            util(nums,pos+1);
            swap(nums[i],nums[pos]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        util(nums, 0);
        return res;
    }
};

// py3
class Solution:
    def permute(self, arr: List[int]) -> List[List[int]]:
        perms = []
        self.helper(arr, [], perms)
        return perms
    
    def helper(self, arr, perm, perms):
        if not len(arr) and len(perm) > 0:
            perms.append(perm)
        else:
            for i in range(len(arr)):
                newArr = arr[:i] + arr[i+1:]
                newperm = perm.copy() + [arr[i]]
                self.helper(newArr, newperm, perms)
                
    
        
    
