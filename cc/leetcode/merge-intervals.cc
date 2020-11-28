// O(nlogn) time | O(n) space
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        res.push_back(a[0]);
        for(int i = 1; i < a.size(); i++){
            if(res.back()[1] >= a[i][0]){
                res.back()[1] = max(res.back()[1], a[i][1]);
            }
            else res.push_back(a[i]);
        }
        return res;
    }
};
