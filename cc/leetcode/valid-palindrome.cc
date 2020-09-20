class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        int l = 0, r = s.size() - 1;
        char cl, cr;
        while(l < r){
            cl = s[l];
            cr = s[r];
            while(l + 1 < s.size() && !(cl >= 'a' && cl <= 'z' || (cl >= '0' && cl <= '9'))){
                if(cl >= 'A' && cl <= 'Z')
                    cl = cl -'A' + 'a';
                else
                    cl = s[++l];
            }
            if(l>=r) break;
            while(r > 0 && !(cr >= 'a' && cr <= 'z' || (cr >= '0' && cr <= '9'))){
                if(cr >= 'A' && cr <= 'Z')
                    cr = cr - 'A' + 'a';
                else
                    cr = s[--r];
            }
            if(l>=r) break;
            
            if(cl != cr)
                return false;
            l++,r--;
        }
        return true;
    }
};
