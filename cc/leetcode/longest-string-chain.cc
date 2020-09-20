class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int>present;
        sort(words.begin(), words.end(), [](string a, string b){
            return a.length() < b.length(); 
        });
        for(int i = 0; i < words.size(); i++){
            present[words[i]] = i;
        }
        vector<int> dp(words.size(), 1);
        
        for(int i = 1; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                string sub = 
                    words[i].substr(0, j) + words[i].substr(j+1, words[i].size()-1);
                if(present.find(sub) != present.end())
                    dp[i] = max(dp[present[sub]] + 1, dp[i]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};