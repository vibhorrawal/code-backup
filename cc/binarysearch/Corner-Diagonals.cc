// O(1) space and time
int solve(int n) {
    if(n < 3) return 0;
    if(n & 1) return n*n - 2*n + 1;
    else return n*n -2*n;
}
