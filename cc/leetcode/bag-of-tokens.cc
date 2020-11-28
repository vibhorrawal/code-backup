// O(nlogn) time | O(1) space
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int lo = 0, hi = tokens.size()-1;
        int points = 0, res = 0;
        if(tokens.size() == 0 || P < tokens[lo]) return 0;
        while(lo <= hi && P >= 0){
            if(P >= tokens[lo]){
                points++;
                P -= tokens[lo++];
                res = max(points, res);
            }
            else {
                P += tokens[hi--];
                points--;
            }
        }
        return res;
    }
};
