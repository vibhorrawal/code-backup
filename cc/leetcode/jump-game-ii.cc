// AC
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        int jumps = 1, steps = nums[0];
        int maxReach = nums[0];
        for(int i = 1; i < n; i++){
            if(i == n-1)
                return jumps;
            steps--;
            maxReach = max(nums[i] + i, maxReach);
            if(steps == 0){
                jumps++;
                steps = maxReach - i;
                if(steps <= 0) // maxReach <= i
                    return -1;
            }
        }
        return -1;
    }
};

// AC
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        int jumps = 0, steps = nums[0];
        int maxReach = nums[0];
        for(int i = 1; i< n-1; i++){
            maxReach = max(nums[i] + i, maxReach);
            steps--;
            if(steps == 0){
                jumps++;
                steps = maxReach - i;
            }
        }
        return jumps + 1;
    }
};

// tle
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n, 1e9+7);
        jumps[0] = 0;
        for(int i = 1; i< n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] + j >= i)
                    jumps[i] = min(jumps[j]+1, jumps[i]);
            }
        }
        return jumps[n-1];
    }
};

//tle
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ways(n, 1e9+7);
        ways[n-1] = 0;
        for(int i = nums.size()-2; i >= 0; i--){
            for(int j = i; j <= min(n-1, nums[i] + i); j++){
                ways[i] = min(ways[j]+1, ways[i]);
            }
        }
        return ways[0];
    }
};