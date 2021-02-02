// O(log(n)) time | O(1) space
class Solution {
public:
    int mySqrt(int x) {
        long n = 0;
        while(n * n <= x) n++;
        return n - 1;
    }
};

// template 1 BS Solution, refer: https://leetcode.com/explore/learn/card/binary-search/125/template-i/950/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        long l = 1, r = x;
        while(l <= r){
            long m = l + (r-l)/2;
            if(m * m <= x and x < (m + 1) * (m + 1)) return m; // comment this if you want to uncomment the below line
            if(m > x / m) r = m - 1;
            else{
                // if((m+1) > x / (m+1)) return m;
                l = m + 1;
            }
        }
        return -1;
    }
};
