// O(N) time | O(1) space
int solve(vector<int>& tasks, int k) {
    int t = 0;
    map<int,int> mp;
    for(int x : tasks){
        if(mp.count(x)){
            if(t - mp[x] >= k){
                t++;
            }
            else{
                t += k - (t - mp[x]) + 1;
            }
        }
        else{
            t++;
        }
        mp[x] = t;
    }
    return t;
}

// cleaner
int solve(vector<int>& tasks, int k) {
    int t = 0;
    map<int,int> mp;
    for(int x : tasks){
        if(mp.count(x)){
            t = max(t, mp[x] + k + 1);
        }
        mp[x] = t++;
    }
    return t;
}
