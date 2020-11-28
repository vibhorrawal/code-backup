// O(n) space | O(n) time
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n), res(n);
        left[0] = 1;
        for(int i = 1; i < n; i++) left[i] = left[i-1] * nums[i-1];
        right[n-1] = 1;
        for(int i = n-2; i >= 0; i--) right[i] = right[i+1] * nums[i+1];
        for(int i = 0; i < n; i++)
            res[i] = left[i] * right[i];
        return res;
    }
};

// O(1) space | O(n) time
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        long prod = 1, count0 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i]) prod *= nums[i];
            else {
                res[i] = 1;
                count0++;
            }
        }

        if(count0){
           if(count0 == 1)
           {
               for(int i = 0; i < n; i++)
                    if(res[i]) res[i] = prod;
           }
            else return vector<int>(n);
        }
        else {
            for(int i = 0; i < n; i++)
                res[i] = prod / nums[i];
        }
        return res;
    }
};
