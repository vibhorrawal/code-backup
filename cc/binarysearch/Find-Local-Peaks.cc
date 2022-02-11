//  O(N) time and space
vector<int> solve(vector<int>& a) {
    vector<int> res;
    const int n = a.size();
    if(n < 2) return res;
    if(a[0] > a[1]) res.push_back(0);
    for(int i = 1; i < n-1; i++){
        if(a[i] > a[i-1] and a[i] > a[i+1]) res.push_back(i);
    }
    if(a[n-1] > a[n-2]) res.push_back(n-1);
    return res;
}