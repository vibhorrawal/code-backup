// O(n) time | O(1) space
int solve(vector<int>& nums) {
    if(nums.size() < 2) return nums[0];
    int x = gcd(nums[0], nums[1]);
    for(int i : nums) x = gcd(x,i);
    return x;
}


// gcd implementation
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}