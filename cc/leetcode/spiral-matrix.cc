class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int> res;
        if(v.size() == 0)
            return res;
        int l,r,u,d;
        d = v.size()-1;
        r = v[0].size()-1;
        l = u = 0;
        int count = 1;
        while(l <= r && u <= d){
            if(count % 4 == 1){
                for(int i = l; i <= r; i++) res.push_back(v[u][i]);
                u++;
            }
            if(count % 4 == 2){
                for(int i = u; i <= d; i++) res.push_back(v[i][r]);
                r--;
            }
            if(count % 4 == 3){
                for(int i = r; i >= l; i--) res.push_back(v[d][i]);
                d--;
            }
            if(count % 4 == 0){
                for(int i = d; i >= u; i--) res.push_back(v[i][l]);
                l++;
            }
            count++;
        }
        return res;
    }
};
