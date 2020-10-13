// greedy O(n) space and time
class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> freq;
        for(char c : s) freq[c]++;
        string res = "";
        vector<bool> vis(26, false);
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(vis[c-'a']) {
                freq[c]--;
                continue;
            }
            while(res.size() > 0 && res.back() > c && freq[res.back()] > 0) {
                vis[res.back() -'a'] = false;
                res.pop_back();
            }
            vis[c-'a'] = true;
            res += c;
            freq[c]--;
        }
        return res;
    }
};
