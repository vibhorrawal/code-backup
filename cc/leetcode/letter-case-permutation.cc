// O(2^n) time | O(2^n * n) space
class Solution {
    vector<string> res;
    string s;
public:
    void util(int pos){
        if(pos == s.size()){
            res.push_back(s);
            return;
        }        
        if(isdigit(s[pos])){
            util(pos+1);
            return;
        }
        s[pos] = toupper(s[pos]);
        util(pos+1);
        s[pos] = tolower(s[pos]);
        util(pos+1);
    }
    vector<string> letterCasePermutation(string S){
        s = S;
        util(0);
        return res;
    }
};
