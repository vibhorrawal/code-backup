// O(n) time and space
vector<int> solve(vector<int>& nums) {
    map<int,int> freq;
    vector<int> res;
    for(int x : nums) freq[x]++;
    for(auto &it : freq)
        if(it.second > 1) it.second--;
    for(int x : nums){
        if(freq[x]-- > 0)
            res.push_back(x);
    }
    return res;
}
