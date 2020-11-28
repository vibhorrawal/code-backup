// O(n) time | O(1) space
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l < r){
            int n = numbers[l] + numbers[r];
            if(n == target) return {l+1, r+1};
            if(n > target) r--;
            else l++;
        }
        return {};
    }
};
