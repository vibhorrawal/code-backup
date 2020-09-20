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

// O(nlong(n)) time | O(n) space
class Solution {
    int binSearch(int val, vector<int>& nums, vector<int>& indices, int len){
        int l = 1, r = len, leftMin = 0;
        while(l<=r){
            int m = (l+r)/2;
            int ind = indices[m];
            if(nums[ind] == val)
                return m;
            else if(nums[ind] < val){
                leftMin = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return leftMin + 1;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return n;
        vector<int> indices(n + 1, -1);
        int len = 0;
        for(int i = 0; i < n; i++){
            int ind = binSearch(nums[i], nums, indices, len);
            if(ind > len) len++;
            indices[ind] = i;
        }
        return len;
    }
};