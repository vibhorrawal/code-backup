class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int,int>>> sum;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1;j < nums.size(); j++){
                sum[nums[i] + nums[j]].push_back({i,j});
            }
        }
        set<vector<int>> s;
        for(auto it = sum.begin(); it != sum.end(); it++){
            if(sum.find(target - (it->first)) != sum.end()){
                vector<pair<int,int>> v1 = it->second;
                vector<pair<int,int>> v2 = sum[target - it->first];
                for(auto i: v1){
                    for(auto j: v2){
                        if(!(i.first == j.first || i.first == j.second || 
                             i.second == j.first || i.second == j.second)){
                            vector<int> v({nums[i.first], nums[i.second], nums[j.first], nums[j.second]});
                            sort(v.begin(), v.end());
                            s.insert(v);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res (s.begin(), s.end());
        return res;
    }
};

// smarter way (but isnt exaclty the answer for this particular ques
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int, vector<pair<int, int>>> sum;
        vector<vector<int>> res;
        if(nums.size() < 4)
            return res;
        for(int i = 1; i < nums.size()-1; i++){
            for(int j = i+1; j< nums.size(); j++){
                int rem = target - nums[i] - nums[j];
                auto it = sum.find(rem);
                if(it == sum.end())
                    continue;
                for(auto t: it->second)
                    res.push_back({nums[t.first], nums[t.second], nums[i], nums[j]});
            }
            
            for(int k = 0; k < i; k++){
                sum[nums[i] + nums[k]].push_back({i,k});
            }
        }
        return res;
    }
};