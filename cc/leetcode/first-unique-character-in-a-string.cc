O(n) time | O(n) space
class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            if(mp.count(s[i]) == 0)
                q.push(i);
            mp[s[i]]++;
        }
            q.pop();
        return q.empty() ? -1 : q.front();
    }
};
