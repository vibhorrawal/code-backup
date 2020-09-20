// AC
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int leftMostGoodIdx = nums.size() - 1;
        for(int i = nums.size()-2; i >= 0;i--){
            if(nums[i] + i >= leftMostGoodIdx)
                leftMostGoodIdx = i;
        }
        return leftMostGoodIdx == 0;
    }
};

//
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> jump(nums.size(), false);
        jump[nums.size()-1] = true;
        for(int i = nums.size()-2; i>=0;i--){
            for(int j = i+1; j <= min((int)nums.size()-1, nums[i]+i); j++){
                if(jump[j]){
                    jump[i] = true;
                    break;
                }
            }
        }
        return jump[0];
    }
};

//
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> jump(nums.size(), false);
        jump[nums.size()-1] = true;
        for(int i = nums.size()-1; i>=0;i--){
            for(int j = i; j >=0; j--){
                if(!jump[j] && j + nums[j] >= i)
                    jump[j] = jump[i];
            }
        }
        return jump[0];
    }
};

//
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> jump(nums.size(), false);
        jump[nums.size()-1] = true;
        for(int i = nums.size()-1; i>=0;i--){
            for(int j = i; j >=0; j--){
                if(j + nums[j] >= i)
                    jump[j] = max(jump[i], jump[j]);
            }
        }
        return jump[0];
    }
};

