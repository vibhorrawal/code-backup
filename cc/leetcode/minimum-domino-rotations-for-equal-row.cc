// O(n) time | O(n) space
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        map<int,int> countA, countB, same;
        int n = A.size();
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[i]) same[B[i]]++;
            countA[A[i]]++;
            countB[B[i]]++;
        }
        for(int i : A){
            if(countA[i] + countB[i] - same[i] == n)
                return min(n-countA[i], n-countB[i]);
        }
        return -1;
    }
};
