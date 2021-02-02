// O(N) time | O(1) space
bool solve(int n, vector<int>& a) {
    if(a.size() == 1)
        return n == 0 || (n == 1 && a[0] == 0);
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 1) continue;
        int j = i;
        while(j < a.size() && a[j] == 0){
            j++;
        }
        int b = (i == 0 ? -1 : i);
        int e = (j == a.size() ? j-1 : j - 2);
        for(int c = e; c > b; c-=2){
            a[c] = 1;
            count++;
        }
    }
    for(int i : a) cout<<i<<' ';
    return n <= count;
}

// cleaner
bool solve(int n, vector<int>& a) {
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i]) continue;
        if((i == 0 || a[i-1] == 0) &&
        (i == a.size()-1 || a[i+1] == 0)){
            count++;
            a[i] = 1;
        }
    }
    return count >= n;
}

// alternate
bool solve(int n, vector<int>& a) {
    a.insert(a.begin(), 0);
    a.push_back(0);
    a.push_back(1);
    int gap = 0, cnt = 0;
    for(int x : a){
        if(x == 0) gap++;
        else{
            cnt += (gap - 1) / 2;
            gap = 0;
        }
    }
    return cnt >= n;
}
