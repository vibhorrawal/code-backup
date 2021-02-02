// O(logn) time
bool solve(int n) {
    if(n == 0) return false;
    int k = log2(n);
    return n == pow(2,k);
}

// O(1) time and space
bool solve(int n) {
    return (n & (n-1)) == 0 and n;
}
