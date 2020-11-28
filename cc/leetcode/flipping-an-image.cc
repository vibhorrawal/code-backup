// O(mn) time | O(1) space
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(vector<int> &t : A){
            reverse(t.begin(), t.end());
            for(int &x: t) x = !x;
        }
        return A;
    }
};
