// O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

//
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if(n & 1)
                count++;
            n = n>>1;
        }
        return count;
    }
};

//
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count++;
            n = n & (n-1);
        }
        return count;
    }
};
