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
