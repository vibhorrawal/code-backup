// O(n*size_of_string) time and space
class Solution {
    string m[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

public:
    string morse(string s){
        string res;
        for(char c : s){
            res += m[c-'a'];
        }
        return res;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        for(string word : words)
            s.insert(morse(word));
        return s.size();
    }
};
