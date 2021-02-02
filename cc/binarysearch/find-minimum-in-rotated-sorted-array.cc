// O(logn) time | O(1) space
class Solution {
public:
    int findMin(vector<int>& a) {
        if(a.size() == 0) return -1;
        if(a.size() == 1) return a[0];
        int l = 0, r = a.size()-1, n = a.size();
        while(l <= r){
            if(a[l] <= a[r]) return a[l];
            int m = (l + r)/2;
            if(m and a[m] < a[m-1]) return a[m];
            if(a[l] <= a[m] and a[m] > a[r]){
                l = m + 1;
            }
            else r = m - 1;
        }
        return a[l];
    }
};


// more verbose binary search
class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        if(n == 0) return -1;
        if(n == 1) return a[0];
        if(a[0] < a[n-1]) return a[0];
        int l = 0, r = n-1;
        while(l <= r){
            int m = (l + r) / 2;
            if(m > 0 and a[m-1] > a[m]) return a[m];
            if(m < n-1 and a[m] > a[m+1]) return a[m+1];
            if(a[l] < a[m]) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};
