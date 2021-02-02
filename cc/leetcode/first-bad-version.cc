// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// O(logn) time | O(1) space
class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n, first = -1;
        while(l <= r){
            int m = (l+r) / 2;
            if(isBadVersion(m)){
                r = m - 1;
                first = m;
            }
            else{
                l = m + 1;
            }
        }
        return first;
    }
};

// Binary Search template 2, refer here: https://leetcode.com/explore/learn/card/binary-search/126/template-ii/947/
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while(l < r){
            int m = (r-l)/2 + l;
            if(isBadVersion(m)) r = m;
            else l = m + 1;
        }
        if(isBadVersion(l)) return l;
        return l-1;
    }
};
