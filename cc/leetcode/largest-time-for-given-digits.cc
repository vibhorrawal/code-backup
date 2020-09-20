class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        assert(A.size() == 4);
        sort(A.begin(), A.end());
        string ans = , temp = ;
        do{
            if(((A[0] == 2 && A[1] < 4) ||  (A[0] < 2))
               && A[2] < 6)
                temp = to_string(A[0]) + to_string(A[1]) + : + to_string(A[2]) + to_string(A[3]);
            ans = max(ans, temp);
        } while(next_permutation(A.begin(), A.end()));
        return ans;
    }
};
