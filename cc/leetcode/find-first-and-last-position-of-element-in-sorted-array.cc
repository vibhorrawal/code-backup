class Solution {
    int t;
    int upper_bound(vector<int>& v){
        int l=0,r=v.size()-1,m, upper = -1;
        while(l <= r){
            m = (l+r)/2;
            
            if(v[m] == t){
                upper = m;
                l = m + 1;
            }
            else if(v[m] < t)
                l = m + 1;
            else
                r = m - 1;
        }
        return upper;
    }
    int lower_bound(vector<int>& v){
        int l=0,r=v.size()-1,m, lower = -1;
        while(l <= r){
            m = (l+r)/2;
            
            if(v[m] == t){
                lower = m;
                r = m - 1;
            }
            else if(v[m] < t)
                l = m + 1;
            else
                r = m - 1;
        }
        return lower;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        t = target;
        int u = upper_bound(nums);
        int l = lower_bound(nums);
        return {l,u};
    }
};
