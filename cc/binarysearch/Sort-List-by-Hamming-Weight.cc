// O(NlogN) time | O(1) space
vector<int> solve(vector<int>& a) {
    sort(a.begin(), a.end(), [](int i, int j){
        int bi = __builtin_popcount(i), bj = __builtin_popcount(j);
        if(bi == bj) return i < j;
        return bi < bj;
    });
    return a;
}