// O(k * log(n)) time | O(n) space
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        vector<int> res;
        for(int x : nums){
           freq[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto [i,c] : freq) pq.push({c,i});
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
