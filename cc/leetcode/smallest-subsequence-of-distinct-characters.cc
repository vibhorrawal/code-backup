// O(n) time | O(1) space greedy stack
class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        vector<int> lastIdx(26), used(26, 0);
        for(int i = 0; i < s.size(); i++) lastIdx[s[i]-'a'] = i;
        
        for(int i = 0; i < s.size(); i++){
            int idx = s[i] - 'a';
            if(used[idx]) continue;
            while(res.size() && res.back() > s[i] && lastIdx[res.back() - 'a'] > i){
                used[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
            used[idx] = 1;
        }
        return res;
    }
};
