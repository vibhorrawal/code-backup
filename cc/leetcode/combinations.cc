// O(2^n) time | nCk space
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        int upto = (1<<n);
        for(int i = 0; i < upto; i++){
            if(__builtin_popcount(i) == k){
                vector<int> t;
                for(int j = 0; j < 32; j++){
                    if(i & (1<<j)){
                        t.push_back(j+1);
                    }
                }
                if(t.size()) res.push_back(t);
            }
        }
        return res;
    }
};
