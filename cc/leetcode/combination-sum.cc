// O(2^n) time and space
class Solution {
    set<vector<int>> s;
    vector<int> arr;
    void util(vector<int> temp, int target, int pos){
        if(pos == arr.size())
            return;
        if(target == 0){
            s.insert(temp);
            return;
        }
        util(temp, target, pos+1);
        
        if(target >= arr[pos]){
            target -= arr[pos];
            temp.push_back(arr[pos]);
            util(temp, target, pos+1);
            util(temp, target, pos);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        arr = candidates;
        vector<int> temp;
        util(temp, target, 0);
        vector<vector<int>> res(s.begin(), s.end());
        
        return res;
    }
};
