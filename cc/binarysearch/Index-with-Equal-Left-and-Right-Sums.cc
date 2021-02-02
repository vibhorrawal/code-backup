// O(n) time and space
int solve(vector<int>& a) {
    vector<int> right(a.size());
    for(int i = a.size()-2; i >= 0; i--)
        right[i] = right[i+1] + a[i+1];
    int left = 0;
    for(int i = 0; i < a.size(); i++){
        if(left == right[i])
            return i;
        left += a[i];
    }
    return -1;
}

// O(n) time | O(1) space
int solve(vector<int>& a) {
    int sum = accumulate(a.begin(), a.end(), 0), left = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] + left * 2 == sum) return i;
        left += a[i];
    }
    return -1;
}
