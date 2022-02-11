// O(n * WORD)
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> reversed;
        string word;
        while(getline(ss, word, ' ')) {
            if(word == "") continue;
            reversed.push_back(word);
        }
        reverse(reversed.begin(), reversed.end());
        s = "";
        for(string word: reversed) {
            s += word + " ";
        }
        s.pop_back();
        return s;
    }
};
