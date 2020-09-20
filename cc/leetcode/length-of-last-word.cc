// O(n) time | O(1) space
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, i = 0, j = 0, temp;
        while(i < s.size()){
            while(i < s.size() && s[i] == ' ') 
                i++;
            while(j < s.size() && s[j] != ' ')
                j++;
            temp = j - i;
            i = ++j;
            if(temp > 0)
                len = temp;
        }
        return len;
    }
};

//O(n) time | O(n) space
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string sub;
        int len = 0;
        while(getline(ss, sub, ' ')){
            len = sub.length() ? sub.length() : len;
        }
        return len;
    }
};