class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> s;
        for(auto n: nums) s.insert(n);
        if(s.size() < 3)
            return *s.begin();
        s.erase(s.begin());
        s.erase(s.begin());
        return *s.begin();
    }
};

//
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long f = -1e17;
        long s = -1e17, t = -1e17;
        int c = 0;
        for(auto x: nums){
            if(x > f){
                t = s;
                s = f;
                f = x;
            }
            else if(f > x && x > s){
                t = s;
                s = x;
            }
            else if(s > x && x > t){
                t = x;
            }
        }
        
        if(t != -1e17) return t;
        else return f;
    }
};