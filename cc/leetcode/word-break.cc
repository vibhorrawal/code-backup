// O(2^n) time | O(n) space
class Solution {
    string s;
    set<string> dict;
    map<int, bool> cache;
    bool util(int b){
        if(b == s.size())
            return cache[b] = true;
        if(cache.find(b) != cache.end())
            return cache[b];
        
        for(int i = b;i < s.size(); i++){
            string sub = s.substr(b,i-b+1);
            if(dict.find(sub) != dict.end())
                if(util(i+1))
                    return cache[b] = true;
        }
        return cache[b] = false;
    }
public:
    bool wordBreak(string ss, vector<string>& wordDict) {
        s = ss;
        for(string word: wordDict)
            dict.insert(word);
        return util(0);
    }
};