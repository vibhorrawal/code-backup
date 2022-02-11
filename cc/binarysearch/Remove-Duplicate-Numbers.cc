// O(K) space | O(N) time
vector<int> solve(vector<int>& nums) {
    map<int,int> freq;
    vector<int> res;
    for(int x : nums) freq[x]++;
    for(int x : nums) if(freq[x] == 1) res.push_back(x);
    return res;
}