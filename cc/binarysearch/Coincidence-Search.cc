// O(n * log(n)) time
int solve(vector<int>& nums) {
    int count = 0;
    for(int x : nums){
        int lo = 0, hi = nums.size()-1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] == x){
                count++;
                break;
            }
            else if(nums[mid] < x) lo = mid + 1;
            else hi = mid -1;
        }
    }
    return count;
}


// O(n) time | O(logn) recursive stack space
int ans;
vector<int> a; // using global var to write less function parameters

void bs(int l, int r, int low, int high){
    if(l <= r){
        int m = (l + r)/2;
        if(low <= a[m] and a[m] <= high) ans++;
        bs(l, m-1, low, min(a[m], high));
        bs(m+1, r, max(a[m], low), high);
    }
}
int solve(vector<int>& nums) {
    if(nums.size() == 1) return 1;
    ans = 0; a = nums;
    bs(0, nums.size()-1, INT_MIN, INT_MAX);
    return ans;
}
