// O(n) time and space
bool solve(vector<int>& nums) {
    map<int,int> freq;
    for(int x : nums) freq[x]++;
    int gcd = freq[nums[0]];
    for(auto it : freq)
        gcd = __gcd(gcd, it.second);
    return gcd >= 2;
}
