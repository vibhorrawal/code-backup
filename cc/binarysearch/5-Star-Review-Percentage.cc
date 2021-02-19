// O(N) time | O(1) space
int solve(vector<vector<int>>& r, int threshold) {
    int total = 0, present = 0;
    for(auto &it : r){
        total += it[1];
        present += it[0];
    }
    if(100 * present >= threshold * total) return 0;
    return ceil( (threshold * total - 100.0 * present) / (100 - threshold) );
}
