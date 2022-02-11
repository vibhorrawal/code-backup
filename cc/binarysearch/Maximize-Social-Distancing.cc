// O(N) time | O(1) space
int solve(vector<int>& s) {
    int ans = 0, l = 0;
    while(s[l] == 0) l++;
    ans = l;
    l = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i]) l = 0;
        else {
            l++;
            ans = max(ans, (l + 1)/2);
        }
        if(i == s.size()-1) ans = max(ans, l);
    }
    return ans;
}

// cleaner
int solve(vector<int>& s) {
    int ans = 0, last = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i]) {
            if(last == -1) ans = max(ans, i);
            last = i;
        }
        else {
            ans = max(ans, (i - last + 1)/2);
        }
    }
    ans = max(ans, (int) s.size() - last - 1);
    return ans;
}

// easier to think but O(N) space
int solve(vector<int>& seats) {
    const int n = seats.size(), INF = 1e9 + 7;
    vector<int> dist(n, INF);
    for(int i = 0; i < n; i++) {
        if(seats[i] == 1) dist[i] = 0;
        else if(i > 0) dist[i] = min(dist[i-1] + 1, dist[i]);
    }
    for(int i = n - 2; i >= 0; i--) {
        dist[i] = min(dist[i+1] + 1, dist[i]);
    }
    return *max_element(dist.begin(), dist.end());
}