// O(mn) time | O(1) space
class Solution {
    int lcp(string s, string t){
        int i = -1;
        while(i+1 < min(s.size(), t.size()) && s[i+1] == t[i+1])
            i++;
        
        return i;
    }
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.size() == 0)
            return ;
        if(str.size() == 1)
            return str[0];
        int ind = INT_MAX;
        for(int i = 0; i < str.size()-1; i++)
            ind = min(ind, lcp(str[i], str[i+1]));
        return str[0].substr(0, ind+1);
    }
};
