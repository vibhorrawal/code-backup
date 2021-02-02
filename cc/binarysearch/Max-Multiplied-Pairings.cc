// O(NlogN + MlogM) time | O(N + M) space
int solve(vector<int>& nums, vector<int>& multipliers) {
    deque<int> a,b;
    sort(nums.begin(), nums.end());
    sort(multipliers.begin(), multipliers.end());
    for(int i : nums) a.push_back(i);
    for(int x : multipliers) b.push_back(x);
    int ans = 0;
    while(a.size() && b.size()){
        int x = a.front() * b.front();
        int y = a.back() * b.back();
        if(x > y){
            ans += x;
            a.pop_front(); b.pop_front();
        }
        else{
            ans += y;
            a.pop_back(); b.pop_back();
        }
    }
    return ans;
}

// O(1) space
int solve(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int la = 0, ra = a.size()-1, lb = 0, rb = b.size()-1;
    int ans = 0;
    while(la <= ra and lb <= rb){
        int x = a[la] * b[lb], y = a[ra] * b[rb];
        if(x > y){
            ans += x;
            la++, lb++;
        }
        else{
            ans += y;
            ra--, rb--;
        }
    }
    return ans;
}
