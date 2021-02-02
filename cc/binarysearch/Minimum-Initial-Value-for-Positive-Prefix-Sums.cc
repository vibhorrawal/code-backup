// O(N) time | O(1) space
int solve(vector<int>& nums) {
    int sum = 0, psum = 0;
    for(int x : nums){
        sum += x;
        psum = min(sum, psum);
    }
    return 1 - psum;
}
