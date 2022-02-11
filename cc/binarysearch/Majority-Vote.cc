// Moore's voting algo
https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
// O(N) time | O(1) space
int solve(vector<int>& nums) {
    int vote = nums[0], count = 0;
    for (int n : nums) {
        if (vote == n)
            count++;
        else
            count--;
        if (count <= 0) {
            vote = n;
            count = 1;
        }
    }
    count = 0;
    for (int n : nums)
        if (vote == n) count++;
    if (count <= nums.size() / 2) return -1;
    return vote;
}

// better
// O(NlogN) time | O(1) space
int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int vote = nums[n / 2];
    auto it = equal_range(nums.begin(), nums.end(), vote);
    if (it.second - it.first > n / 2)
        return vote;
    else
        return -1;
}