// O(nlogn + mlogm) time | O(1) space
int solve(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sum = accumulate(a.begin(), a.end(), 0) - accumulate(b.begin(), b.end(), 0);
    if(sum < 0) {
        swap(a,b);
        sum = -sum;
    }
    int ra = a.size() - 1, lb = 0;
    int ans = 0;
    while(sum > 0 && ra >= 0 && lb < b.size()){
        ans++;
        int x = a[ra] - 1;
        int y = 6 - b[lb];
        if(x > y){
            sum -= x;
            ra--;
        }
        else {
            sum -= y;
            lb++;
        }
    }
    while(sum > 0 && ra >= 0){
        ans++;
        sum -= a[ra--] - 1;
    }
    while(sum > 0 && lb < b.size()){
        ans++;
        sum -= 6 - b[lb++];
    }
    if(sum > 0) return -1;
    return ans;
}

// greedy O(m+n) time } O(1) space
int solve(vector<int>& a, vector<int>& b) {
    int sum_a = accumulate(a.begin(), a.end(), 0), sum_b = accumulate(b.begin(), b.end(), 0);
    int diff = sum_a - sum_b;
    if(diff < 0) {
        swap(a, b);
        diff = -diff;
    }
    int cnt[6] = {0};
    for(int x : a) cnt[x-1]++;
    for(int x : b) cnt[6-x]++;

    int ans = 0;
    for(int i = 5; i >= 1 and diff > 0; i--){
        int elements = min(cnt[i], (int) ceil(((double) diff) / i));
        ans += elements;
        diff -= elements * i;
    }
    if(diff > 0) return -1;
    return ans;
}
