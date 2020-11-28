
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return n;
        vector<int> dp(n, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// O(nlong(n)) time | O(n) space
class Solution {
    int binSearch(int val, vector<int>& nums, vector<int>& indices, int len){
        int l = 1, r = len, leftMin = 0;
        while(l<=r){
            int m = (l+r)/2;
            int ind = indices[m];
            if(nums[ind] == val)
                return m;
            else if(nums[ind] < val){
                leftMin = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return leftMin + 1;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return n;
        vector<int> indices(n + 1, -1);
        int len = 0;
        for(int i = 0; i < n; i++){
            int ind = binSearch(nums[i], nums, indices, len);
            if(ind > len) len++;
            indices[ind] = i;
        }
        return len;
    }
};
