// O(n^2) time | O(n^2) space
class Solution {
    int count(string s, int pos){
        int i = 0;
        while(s[pos] == s[pos+i]) i++;
        return i;
    }
public:
    string countAndSay(int n) {
        if(n == 1)
            return 1;
        
        string rem = countAndSay(n-1);
        string ans = ;
        int i = 0;
        while(i < rem.size()){
            int c = count(rem,i);
            ans += to_string(c) + rem[i];
            i = i + c;
        }
        return ans;
    }
};
