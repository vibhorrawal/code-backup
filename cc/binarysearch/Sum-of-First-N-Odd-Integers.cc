// O(N) time | O(1) space
int solve(int n) {
    int sum = 0;
    for (int i = 1, count = 0; count < n; i += 2, count++) {
        sum += i;
    }
    return sum;
}

// O(1) time
int solve(int n) {
    return n * n;
}
