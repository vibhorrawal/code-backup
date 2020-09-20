// O(numOfStr * length_of_string) time and space
class Solution {
    string freq(string s){
        vector<int> res(26);
        for(char c: s){
            res[c-'a']++;
        }
        string sr(res.begin(), res.end());
        cout<<sr<<endl;
        return sr;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> mp;
        for(string s: strs){
            mp[freq(s)].push_back(s);
        }
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};
