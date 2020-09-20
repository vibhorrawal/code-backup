class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetChar, substrChar;
        for(char c: t)
            targetChar[c]++;
        int uniqueChars = targetChar.size(), uniqueCharsFound = 0;
        int l = 0, r = 0, len = INT_MAX, start = 0;
        while(r < s.size()){
            char rightChar = s[r];
            if(targetChar.find(rightChar) == targetChar.end()){
                r++;
                continue;
            }
            substrChar[rightChar]++;
            if(substrChar[rightChar] == targetChar[rightChar])
                uniqueCharsFound++;
            while(uniqueCharsFound == uniqueChars && l <= r){
                if(r-l+1 < len){
                    start = l;
                    len = r-l+1;
                }
                char leftChar = s[l];
                if(targetChar.find(leftChar) == targetChar.end()){
                    l++;
                    continue;
                }
                if(substrChar[leftChar] == targetChar[leftChar])
                    uniqueCharsFound--;
                substrChar[leftChar]--;
                l++;
            }
            r++;
        }
        if(len == INT_MAX)
            return "";
        return s.substr(start, len);
    }
};