// O(n) time | O(1) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

// O(n) time | O(1) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        for(int start = 0, count = 0; count < n; start++){
            int curr = start;
            int prevEle = nums[start];
            do{
                int next = (curr + k) % n;
                int temp = nums[next];
                nums[next] = prevEle;
                prevEle = temp;
                curr = next;
                count++;
            }while(start != curr);
        }
    }
};