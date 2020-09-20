class Solution {
public:
    int fib(int N) {
        if(N == 1)
            return 1;
        if(N == 0)
            return 0;
        return fib(N-1) + fib(N-2);
    }
};

//
class Solution {
        unordered_map <int, int> mp;
    
public:
    int fib(int N) {
        if(mp.find(N) != mp.end())
            return mp[N];
        if(N == 1)
            return 1;
        if(N == 0)
            return 0;
        return mp[N] = fib(N-1) + fib(N-2);
    }
};

//
class Solution {
    
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        int dp[N+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i<=N; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[N];
    }
};

//
class Solution {
    
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        if(N == 2) return 1;
        int a = 1, b = 1;
        for(int i = 3; i <= N; i++){
            int temp = a + b;
            b = a;
            a = temp;
        }
        return a;
    }
};