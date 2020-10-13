// O(nlogn) time | O(1) space
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// O(n) time | O(1) space
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(256, 0);
        for(char c : s)
            count[c]++;
        
        for(char c : t)
            count[c]--;
        
        for(int i : count)
            if(i != 0)
                return false;
        return true;
    }
};
