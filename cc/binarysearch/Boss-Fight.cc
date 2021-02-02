// O(MN) time and space
vector<vector<int>> solve(vector<int>& fighters, vector<vector<int>>& bosses) {
    vector<vector<int>> res;
    int f = accumulate(fighters.begin(), fighters.end(), 0);
    for(int i = 0; i < bosses.size(); i++){
        if(f > accumulate(bosses[i].begin(), bosses[i].end(), 0)) continue;
        res.push_back(bosses[i]);
    }
    return res;
}
