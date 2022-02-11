// O(N^2) bcz of insert in front of array
vector<int> solve(int n, int lower, int upper) {
    if(upper <= lower) return {};
    vector<int> res = {upper-1, upper, upper-1};
    for(int i = upper-2; i >= lower and res.size() != n; i--) 
        res.push_back(i);
    if(res.size() == n) return res;
    for(int i = upper-2; i >= lower and res.size() != n; i--) 
        res.insert(res.begin(), i);
    if(res.size() == n) return res;
    return {};
}

// O(N) space time
vector<int> solve(int n, int lower, int upper) {
    int maxpossible = (upper - lower + 1) * 2 - 1;
    if(maxpossible < n) return {};
    int backsize = min(n-1, upper - lower + 1);
    int front = n - backsize;
    vector<int> res;
    int s = upper - front;
    while(s < upper) res.push_back(s++);
    while(backsize--) res.push_back(upper--);
    return res;
}

// O(N) time
vector<int> solve(int n, int lower, int upper) {
    if(upper == lower) return {};
    n -= 3; // [upper-1, upper, upper-1] minimum
    int left, right;
    int deltaRight = (upper - 1) - lower;
    right = min(deltaRight, n);
    n -= right;

    int deltaLeft = (upper - 1) - lower;
    left = min(deltaLeft, n);
    n -= left;
    // cout<<left<<' '<<right;
    if(n != 0) return {};

    vector<int> res;
    for(int i = upper - left - 1, cnt = 0; cnt < left; i++, cnt++) res.push_back(i);

    res.push_back(upper-1);
    res.push_back(upper);
    res.push_back(upper-1);

    for(int i = upper - 2, cnt = 0; cnt < right; cnt++,i--) res.push_back(i);

    return res;
}