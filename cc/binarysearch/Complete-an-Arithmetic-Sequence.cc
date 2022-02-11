// O(N) time and space
int solve(vector<int>& a) {
    unordered_set<int> s;
    for(int i = 1; i < a.size(); i++) s.insert(a[i] - a[i-1]);
    int d = INT_MAX;
    for(int i : s) d = min(abs(i), d);
    if(*s.begin() < 0) d *= -1;
    for(int i = 1; i < a.size(); i++)
        if(a[i-1] + d != a[i])
            return a[i-1] + d;
    return (a[0] + a[1]) / 2;
}

// O(N) time | O(1) space
int solve(vector<int>& a) {
    int n = a.size();
    if(n == 2) {
        return (a[0] + a[1])/2;
    }
    int d = min(abs(a[1] - a[0]), abs(a[n-1] - a[n-2]));
    d = (a[1] >= a[0]) ? d : -d; // sign of d will be same for whole array

    for(int i = 1; i < n; i++) {
        if(a[i-1] + d != a[i]) {
            return a[i-1] + d;
        }
    }
    return a[n-1] + d;
}

// another soln
int solve(vector<int>& a) {
    int n = a.size();
    // Sn = n/2 * (a1 + an)
    long long int sum = ((long long int) a[0] + a[n-1]) * (n+1) / 2;
    return -accumulate(a.begin(), a.end(), -sum);
}

// alternate, O(Log(N)) solution
int solve(vector<int>& a) {
    int n = a.size();
    if(n == 2) {
        return (a[0] + a[1]) / 2;
    }
    int l = 0, r = n-1;
    // a[i] = a[0] + d * position
    int d = (a[n-1] - a[0]) / n;
    while(l < r) {
        int m = (l + r)/2;
        if(a[m] == a[0] + m * d) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return a[l] - d;
}