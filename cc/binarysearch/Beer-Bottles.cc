// O(log3(n)) time
int solve(int n) {
    int ans = n;
    int rem = n;
    int extra = 0;
    while(rem >= 3){
        ans += rem / 3;
        extra = rem % 3;
        rem = (rem / 3) + extra;
    }
    return ans;
}

int solve(int full) {
    int drunk = 0, empty = 0;
    while(full){
        drunk += full;
        empty += full;
        full = empty / 3;
        empty = empty % 3;
    }
    return drunk;
}
