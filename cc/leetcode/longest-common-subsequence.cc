// O(mn) time | O(mn) space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> lcs(text1.size()+1, vector<int> (text2.size()+1, 0));
        
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
            if(text1[i-1] == text2[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
        return lcs[text1.size()][text2.size()];
    }
};

// alternate with O(m) space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> odd(text2.size()+1, 0), even(text2.size()+1, 0);
        
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(i % 2){
                    if(text1[i-1] == text2[j-1])
                        odd[j] = 1 + even[j-1];
                    else
                        odd[j] = max(odd[j-1], even[j]);
                }
                else{
                    if(text1[i-1] == text2[j-1])
                        even[j] = 1 + odd[j-1];
                    else
                        even[j] = max(even[j-1], odd[j]);
                }
            }
        }
        if(text1.size() % 2)
            return odd[text2.size()];
        else
            return even[text2.size()];
    }
};

// modifying soln 1 for O(m) space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> lcs(2, vector<int> (text2.size()+1, 0));
        
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
            if(text1[i-1] == text2[j-1])
                lcs[i%2][j] = 1 + lcs[(i-1)%2][j-1];
            else
                lcs[i%2][j] = max(lcs[(i-1)%2][j], lcs[i%2][j-1]);
            }
        }
        return lcs[text1.size()%2][text2.size()];
    }
};