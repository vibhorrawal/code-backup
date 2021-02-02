// O(N) space | O(N) find() 
class TwoSum {
    unordered_map<int,int> mp;
    public:
    TwoSum() {

    }

    void add(int val) {
        mp[val]++;
    }

    bool find(int val) {
        for(auto [a,b] : mp){
            if(mp.count(val-a)){
                if(a == val - a){
                    if(b > 1) return true;
                }
                else{
                    if(mp[val-a] > 0)  return true;
                }
            }
        }
        return false;
    }
};
