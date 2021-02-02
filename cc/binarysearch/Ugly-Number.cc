// O(logN) time | O(1) space
bool solve(int n) {
    for(int i : {2,3,5})
    while(1){
        int k = n / i;
        if(k * i != n) break;
        n = k;
    }
    return n == 1;
}

// alternate
bool solve(int n) {
    for(int i = 2; i <= n and n > 1; i++){
        if(i > 5) return false;
        while(n % i == 0) n /= i;
    }
    return n == 1;
}
