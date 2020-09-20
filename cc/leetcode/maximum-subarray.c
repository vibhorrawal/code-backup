class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int max_so_far = -1e17, max_ending_here = 0;

        for(auto a: nums){
            max_ending_here += a;
            max_so_far = max(max_so_far, max_ending_here);
            
            if(max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
};
