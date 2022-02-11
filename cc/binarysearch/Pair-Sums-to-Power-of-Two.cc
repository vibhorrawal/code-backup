// O(N) time and space
int solve(vector<int>& a) {
    unordered_map<int,int> freq;
    int ans = 0;
    for(int x : a){
        for(int i = 0; i < 31; i++){
            int bit = 1<<i;
            if(bit < x) continue;
            ans += freq[bit - x];
        }
        freq[x]++;
    }
    return ans;
}