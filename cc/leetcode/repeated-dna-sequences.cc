// O(n) space | O(n) time
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> seen;
        set<string> ans;
        string temp = "";
        if(s.size() < 10) return {};
        for(int i =0; i < 10; i++) temp += s[i];
        seen.insert(temp);
        for(int i = 10; i < s.size(); i++){
            temp.erase(temp.begin());
            temp.push_back(s[i]);
            if(seen.count(temp)) ans.insert(temp);
            seen.insert(temp);
        }
        vector<string> res (ans.begin(), ans.end());

        return res;
    }
};
