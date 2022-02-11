// O(N) time | O(1) space
bool solve(vector<int>& a) {
    const int n = a.size();
    int inc = 0, dec = 0;
    for(int i = 1; i < n; i++){
        if(a[i-1] + 1 != a[i]) inc++;
        if(a[i-1] - 1 != a[i]) dec++;
    }
    return (inc < 2) or (dec < 2);
}