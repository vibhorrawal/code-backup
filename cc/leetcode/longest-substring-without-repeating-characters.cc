// O(n) time | O(1) space
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1);
        int start = 0, length = 0;
        for(int i = 0; i < s.size(); i++){
            int ch = s[i];
            if(index[ch] < start){
                index[ch] = i;
            }
            else{
                start = max(start, index[ch] + 1);
                index[ch] = i;
            }
            length = max(i - start + 1, length);
        }
        return length;
    }
};
