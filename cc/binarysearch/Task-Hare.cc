// O(NlogN) time | O(1) space
int solve(vector<int>& tasks, vector<int>& people) {
    sort(tasks.rbegin(), tasks.rend());
    sort(people.rbegin(), people.rend());
    int res = 0;
    int t = 0, p = 0;
    for(int p = 0; p < people.size(); p++){
        while(t < tasks.size() && tasks[t] > people[p])
            t++;
        if(t < tasks.size() && tasks[t] <= people[p])
            res++,t++;
    }
    return res;
}

// other
int solve(vector<int>& t, vector<int>& p) {
    sort(t.begin(), t.end());
    sort(p.begin(), p.end());
    int ans = 0;
    for(int i = 0, j = 0; i < t.size() and j < p.size(); i++){
        while(j < p.size() and p[j] < t[i]) j++;
        if(j < p.size()) ans++, j++;
    }
    return ans;
}
