class Solution {
public:
    int longestMountain(vector<int>& a) {
        int max_l = 0;
        for(int i = 0; i < a.size(); i++){
            int l = i, r = i;
            while(l > 0 && a[l-1] < a[l]) l--;
            while(r +1 < a.size() && a[r] > a[r+1]) r++;
            if(l != i && r != i)
                max_l = max(max_l, r - l + 1);
            i = max(r-1,i);
        }
        return (max_l > 2 ? max_l : 0);
    }
};
