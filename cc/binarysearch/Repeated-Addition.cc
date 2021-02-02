// O(N) time
int add(int n){
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int solve(int n) {
    while(n/10) n = add(n);
    return n;
}

// O(1) time and space
int solve(int n) {
    n = n % 9;
    return n == 0 ? 9 : n;
}
