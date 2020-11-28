// O(logn) time and space
class Solution {
    bool isPalin(string s){
        int n = s.size();
        for(int i = 0; i <= n/2; i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
public:
    bool isPalindrome(int x) {
        return isPalin(to_string(x));
    }
};
