// O(N^2 * LogN) time | O(1) space
int solve(vector<int>& a, int target) {
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < a.size()-2; i++){
        for(int j = i+1; j < a.size()-1 ; j++){
            int req = target - a[i] - a[j];
            int k = lower_bound(a.begin() + j + 1, a.end(), req) - a.begin() - j - 1;
            k--;
            if(k < 0) continue;
            ans += k + 1;
        }
    }
    return ans;
}

// O(N^2) time
int solve(vector<int>& a, int target) {
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < a.size()-2; i++){
        int l = i + 1, r = a.size()-1;
        while(l < r){
            int sum = a[i] + a[l] + a[r];
            if(sum >= target) r--;
            else{
                ans += r - l;
                l++;
            }
        }
    }
    return ans;
}