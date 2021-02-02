// O(1) time and space
int solve(int x, int y) {
 return __builtin_popcount(x ^ y);
}

// O(32)
int solve(int x, int y) {
    int ans = 0;
    while(x or y){
        ans += (x & 1) ^ (y & 1);
        x >>= 1;
        y >>= 1;
    }
    return ans;
}
