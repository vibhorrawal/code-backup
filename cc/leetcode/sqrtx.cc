// O(log(n)) time | O(1) space
class Solution {
public:
    int mySqrt(int x) {
        long n = 0;
        while(n * n <= x) n++;
        return n - 1;
    }
};
