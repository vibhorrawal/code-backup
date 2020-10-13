// O(n) time | O(1) space
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        map<char, long> mp;
        int i1 = -1, i2 = -1;
        for(int i = 0; i < (int) A.size(); i++){
            if(A[i] != B[i]) {
                if(i1 == -1) i1 = i;
                else if(i2 == -1) i2 = i;
            }
            if(A[i] == B[i]) mp[A[i]]++;
        }
        if(i2 != -1) swap(A[i1], A[i2]);
        if(i2 != -1 && A == B) return true;
        if(A != B) return false;
        for(auto it : mp) if(it.second >= 2) return true;
        return false;
    }
};
