// O(2^N) space and time
int ans, t;
vector<int> a;

void recur(int pos, int sum){
    if(pos == a.size()){
        ans += sum == t;
        return;
    }
    recur(pos + 1, sum + a[pos]);
    recur(pos + 1, sum - a[pos]);
}
int solve(vector<int>& a_, int target) {
    ans = 0; a = a_; t = target;
    recur(0, 0);
    return ans;
}

// DP
