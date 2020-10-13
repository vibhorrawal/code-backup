// O(n) time | O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int num: nums)
            x = num ^ x;
        return x;
    }
};

// O(n) time | O(n) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> contains;
        for(int num: nums)
            if(contains.count(num))
                contains.erase(num);
            else
                contains.insert(num);
        return *contains.begin();
    }
};
