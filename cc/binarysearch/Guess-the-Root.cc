// O(logn)
int solve(int n) {
    int i = 0;
    while(i * i <= n) i++;
    return i-1;
}

// O(logn)
int solve(int n) {
    return exp(log(n)/2);
}
