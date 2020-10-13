// O(n^2) time | O(1) space
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0 || n == 1)
            return s;

        int maxl = 1;
        int start = 0;
        vector<int> odd(n), even(n);
        int l = 0, r = -1;
        for(int i = 0; i < n; i++){
            int k = (i > r) ? 1 : min(odd[l+r-i], r-i+1);
            while(i - k >= 0 && i + k < n && s[i-k] == s[i+k])
                k++;
            odd[i] = k--;
            if(i + k > r){
                l = i - k;
                r = i + k;
            }
        }

        l = 0, r = -1;
        for(int i = 0; i < n; i++){
            int k = (i > r) ? 0 : min(even[l+r-i+1], r-i+1);
            while(i - k - 1 >= 0 && i + k < n && s[i-k-1] == s[i+k])
                k++;
            even[i] = k--;
            if(i + k > r){
                l = i - k - 1;
                r = i + k;
            }
        }

        for(int i = 0; i < n; i++){
            if(maxl < (odd[i]-1) * 2 + 1){
                maxl = (odd[i] -1) * 2 + 1;
                start = i - (odd[i] - 1);

            }
            if(maxl < even[i] * 2){
                maxl = even[i] * 2;
                start = i - (even[i] -1) -1;
            }
        }
        return s.substr(start, maxl);
    }
};

// elegeant
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s;

        int maxl = 1;
        int start = 0;
        auto expandAroundCentre = [&](int l, int r) {
            while(l >= 0 && r < s.size() && s[l] == s[r])
                l--, r++;
            l++;
            r--;
            if(l < 0 || r >= s.size())
                return;
            int len = r - l + 1;
            if(len > maxl){
                start = l;
                maxl = len;
            }
        };
        for(int i = 0; i < s.size(); i++){
            expandAroundCentre(i,i);
            expandAroundCentre(i,i+1);
        }
        return s.substr(start, maxl);
    }
};

// O(n^2) time | O(n^2) space
// dp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) dp[i][i] = true;
        int start = 0, len = 1;
        for(int gap = 1; gap < n; gap++){
            for(int i = 0, j = gap + i; j < n; i++,j++){
                if(i+1 == j)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1];

                if(dp[i][j] && len < j - i + 1){
                    len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start,len);
    }
};
