// O(N) time and space
int solve(vector<int>& a) {
    if(a.size() < 2) return 0;
    vector<int> d(a.size()-1);
    for(int i = 1; i < a.size(); i++){
        d[i-1] = a[i] - a[i-1];
    }
    int ans = 0;
    for(int i = 0; i < d.size()-1;){
        int j = i + 1, cnt = 0;
        for(; j < d.size(); j++){
            if(d[j] != d[j-1]) break;
            cnt++;
            ans += cnt;
        }
        i = j;
    }
    return ans;
}
