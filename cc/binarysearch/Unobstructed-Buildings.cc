// O(N) time | O(1) space
vector<int> solve(vector<int>& h) {
    vector<int> res;
    int max_here = 0;
    for(int i = h.size()-1; i >= 0; i--){
        if(max_here < h[i]) res.push_back(i);
        max_here = max(max_here, h[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}
