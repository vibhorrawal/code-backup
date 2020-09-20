// O(n) time | O(1) space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int ind = abs(nums[i]) - 1;
            if(nums[ind] < 0)
                return ind + 1;
            nums[ind] *= -1;
        }
        return -1;
    }
};

// floyd hare and turtle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);
        
        hare = nums[0];
        while(tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};
