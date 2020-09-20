// O(n) time and space -> elegant soln
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string modified = (s + s).substr(1, s.size() * 2 -2);
        int pos = modified.find(s);
        if(pos != -1)
            return true;
        else
            return false;
    }
};

// O(n) time and space with lps array
class Solution {
    int createLPSArray(string s){
        int len = 0, i = 1, n = s.size();
        vector<int> lps(n);
        lps[0] = 0;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0)
                    len = lps[len-1];
                else
                    i++;
            }
        }
        return lps[n-1];
    }
public:
    bool repeatedSubstringPattern(string s) {
        int lps_len = createLPSArray(s);
        int n = s.size();
        return (n % (n-lps_len)) == 0 && lps_len != 0;
    }
};