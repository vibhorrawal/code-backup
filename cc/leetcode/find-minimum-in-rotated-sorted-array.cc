// O(logn) time | O(1) space
class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, r = a.size()-1, n = a.size();
        while(l <= r){
            if(a[l] <= a[r]) return a[l];
            int m = (l + r)/2;
            int prev = (m-1 + a.size()) % n;
            int next = (m + 1) % n;
            if(a[prev] > a[m] and a[m] <= a[next]) return a[m];
            if(a[l] <= a[m]) l = m + 1;
            else if(a[m] <= a[r]) r = m - 1;
        }
        return -1;
    }
};
