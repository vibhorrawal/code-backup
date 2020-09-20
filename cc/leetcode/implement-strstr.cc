class Solution {
    vector<int> computeLPS(string s){
        int m = s.size(), len = 0;
        vector<int> lps(m);
        lps[0] = 0;
        int i = 1;
        while(i < m){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0)
                    len = lps[len-1];
                else
                    lps[i++] = 0;
            }
        }
        return lps;
    }
    int kmp(string txt, string pat){
        int n = txt.size(), m = pat.size();
        vector<int> lps = computeLPS(pat);
        int i = 0, j = 0;
        while(i < n){
            if(pat[j] == txt[i])
                i++,j++;
            if(j == m)
                return i - j;
            if(i < n && pat[j] != txt[i]){
                if(j != 0)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        return kmp(haystack, needle);
    }
};