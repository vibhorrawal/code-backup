// O(n) time | O(n) space
// memoisation
class Solution {
    map<int, int> memo;
public:
    int climbStairs(int n) {
        if(memo[n])
            return memo[n];
        if(n == 1 || n == 2)
            return n;
        if(n <= 0)
            return 0;
        return memo[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};

//dp
// O(n) time | O(n) space
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        vector<int> ways(n);
        ways[0] = 1;
        ways[1] = 2;
        for(int i = 2; i < n; i++){
            ways[i] = ways[i-1] + ways[i-2];
        }
        return ways[n-1];
    }
};

// O(n) time | O(1) space
class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int c = 3, a = 1, b = 2;
        n-= 3;
        while(n--){
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};
