// O(n^2) time | O(n) space
class Solution {
    int dist(vector<int> &a, vector<int> &b){
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s;
        vector<vector<int>> p = {p1,p2,p3,p4};
        sort(p.begin(), p.end());
        for(int i = 1; i < 4; i++) if(p[i] == p[i-1]) return false;

        for(int i = 0; i < 4; i++)
            for(int j = i+1; j < 4; j++){
                s.insert(dist(p[i],p[j]));
            }
        return s.size() == 2;
    }
};
