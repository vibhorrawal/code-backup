// binary search
// worst case O(n) | avg case O(logn)
class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        if(n == 0) return -1;
        if(n == 1) return a[0];
        if(a[0] < a[n-1]) return a[0];
        int l = 0, r = n-1;
        while(l < r){
            if(a[l] < a[r]) return a[l];
            int m = (l + r) / 2;
            if(m > 0 and a[m-1] > a[m]) return a[m];
            if(m < n-1 and a[m] > a[m+1]) return a[m+1];
            if(a[m] < a[r]) r = m;
            else if(a[m] > a[r]) l = m + 1;
            else r--;
        }
        return a[l];
    }
};


// if a[l] == a[r] ( == a[m]) then the only way is linear search
class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, r = a.size()-1;
        while(l < r and a[l] > a[r]){
            int m = (l + r)/2;
            if(m and a[m] < a[m-1]) return a[m];
            if(a[m] > a[r]) l = m + 1;
            else r = m;
        }
        return *min_element(a.begin() + l, a.begin() + r + 1);
    }
};

// when values are equal then we search in two halves
class Solution {
    int ans;
    void bs(int l, int r, vector<int> &a){
        if(r - l <= 1){
            ans = min({ans, a[l], a[r]});
            return;
        }
        int m = (l + r)/2;
        if(a[m] >= a[r]) bs(m, r, a);
        if(a[r] >= a[m]) bs(l, m, a);
    }
public:
    int findMin(vector<int>& a) {
        ans = INT_MAX;
        bs(0,a.size()-1,a);
        return ans;
    }
};
