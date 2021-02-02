// O(n) time | O(1) space with modifying given vector
vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    int m = n + 1;
    for(int i = 0; i < nums.size(); i++){
        int id = nums[i] % m;
        nums[id-1] += m;
    }
    int i = 0;
    for(int j = 0; j < nums.size(); j++){
        if(nums[j] / m == 0){
            nums[i++] = j + 1;
        }
    }
    i = n - i;
    while(i-- > 0) nums.pop_back();
    return nums;
}


// O(nlogn) sort time
vector<int> solve(vector<int>& a) {
    vector<int> res;
    sort(a.begin(), a.end());
    for(int i = 1; i <= a.size(); i++){
        if(not binary_search(a.begin(), a.end(), i))
            res.push_back(i);
    }
    return res;
}
