// O(NlogN) time | O(1) space
int f(int sz, vector<int> &a){
    int cnt = 0;
    for(int i : a) cnt += i / sz;
    return cnt;
}
int solve(vector<int>& a, int k) {
    long ans = -1, l = 1, r = INT_MAX;
    while(l <= r){
        long m = (l + r)/2;
        if(f(m, a) >= k){
            l = m + 1;
            ans = m;
        }
        else r = m - 1;
    }
    return ans;
}