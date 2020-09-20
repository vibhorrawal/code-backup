class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> use;
        for(int num: nums){
            use[num] = true;
        }
        int maxl = 0;
        for(int num: nums){
            int count = 0;
            if(!use[num])
                continue;
            int val = num-1;
            while(use[val]){
                count++;
                use[val] = false;
                val--;
            }
            while(use[num]){
                count++;
                use[num] = false;
                num++;
            }
            maxl = max(maxl, count);
        }
        return maxl;
    }
};