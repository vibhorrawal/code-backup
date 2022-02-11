// O(N) space time
int solve(vector<int>& a) {
    const int n = a.size();
    if(n < 3) return 0;
    vector<int> rightMax(n);
    rightMax.back() = 0;
    for(int i = n - 2; i >= 0; i--) 
        rightMax[i] = max(rightMax[i+1], a[i+1]);
    
    int leftMax = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(0, min(leftMax, rightMax[i]) - a[i]);
        leftMax = max(leftMax, a[i]);
    }
    return ans;
}