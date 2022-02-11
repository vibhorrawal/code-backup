// O(NlogN) time | O(1) space
// binary search on answer
bool possible(int h, vector<int> &c) {
    int cnt = 0;
    for(int x : c) if(x >= h) cnt++;
    return cnt >= h;
}

int solve(vector<int>& c) {
    const int n = c.size();
    int l = 0, r = n, ans = -1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(possible(m, c)) {
            l = m + 1;
            ans = max(ans, m);
        } else {
            r = m - 1;
        }
    }
    return ans;
}

// same complexity but different approach, somewhat difficult to come with since takes many trials
int solve(vector<int>& c) {
    sort(c.begin(), c.end());
    int h = 0, n = c.size();
    for(int i = 0; i < n; i++) {
        if(c[i] > h and (n - i >= h)) {
            h = min(c[i], n - i);
        }
    }
    return h;
}

// i forgot how i got here, or if even these are correct
int solve(vector<int>& citations) {
    sort(citations.rbegin(), citations.rend());
    int c = 0;
    while(c < citations.size() && citations[c] > c) c++;
    return c;
}

// same as above
int solve(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    for(int h = citations.size(); h >= 0; h--){
        if(citations[citations.size() - h] >= h) return h;
    }
    return 0;
}
