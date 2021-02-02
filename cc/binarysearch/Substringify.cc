// O(|S| * |T|) time | O(1) space
int solve(string s, string t) {
    int mincost = t.size();
    for(int i = 0; i < s.size(); i++){
        int cost = 0;
        for(int j = 0; j < t.size(); j++){
            if(i + j == s.size()){
                cost = INT_MAX;
                break;
            }
            if(s[i + j] != t[j])
                cost++;
        }
        mincost = min(cost, mincost);
    }
    return mincost;
}
