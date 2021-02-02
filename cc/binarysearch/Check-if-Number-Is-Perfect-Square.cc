// O(n) time
bool solve(int n) {
    int k = 0;
    while(k * k < n) k++;
    return k * k == n;
}

// O(logn) time
bool solve(int n) {
    int l = 0, r = n;
    while(l <= r){
        long m = l + (r-l)/2;
        if(m * m == n) return true;
        if(m * m < n)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}
