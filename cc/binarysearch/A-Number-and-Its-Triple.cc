// O(N) time and space
bool solve(vector<int>& nums) {
    set<int> s;
    for(int n : nums){
        if(s.count(n*3) || (n % 3 == 0 && s.count(n/3)))
            return true;
        s.insert(n);
    }
    return false;
}
