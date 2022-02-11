// O(LogN) time
vector<int> a;
int bs(int l, int r){
    if(l == r) return a[l];
    int m = (l+r)/2;
    if(a[m-1] <= a[m] && a[m+1] <= a[m]) 
        return a[m];
        
    if(a[l] > a[m])
        return bs(l,m-1);
    // else if(a[r] > a[m]) 
        return bs(m+1,r);
}
int solve(vector<int>& b) {
    a = b;
    return bs(0, a.size()-1);
}

https://binarysearch.com/problems/Find-the-Largest-Number-in-a-Rotated-List/solutions/3223257
// this one is Fab
int solve(vector<int>& a) {
    const int n = a.size(), first = a[0];
    int l = 0, r = n - 1, ans = first;
    while(l <= r) {
        // T, T, T, F, F
        //        |
        // find the last True
        int m = (l + r) / 2;
        if(a[m] >= first) {
            l = m + 1;
            ans = max(ans, a[m]);
        } else {
            r = m - 1;
        }
    }
    return ans;
}