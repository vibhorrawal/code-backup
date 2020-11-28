// O(n^2) time | O(1) space
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            int jump = 0, idx = i;
            bool ispos = nums[i] >= 0;
            while(jump <= n){
                idx = (idx + nums[idx]) % n;
                idx = (idx + n) % n;
                jump++;
                // cout<<idx<<' ';
                if((ispos && nums[idx] < 0) || (!ispos && nums[idx] >= 0))
                    break;
                if(idx == i){
                    if(jump > 1) return true;
                    else break;
                }
            }
        }
        return false;
    }
};
