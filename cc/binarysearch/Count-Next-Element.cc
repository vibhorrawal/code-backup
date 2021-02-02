// O(n) space | O(n) time
int solve(vector<int>& nums) {
    set<int> s;
    for(int i : nums) s.insert(i);
    int count = 0;
    for(int i : nums) if(s.count(i+1)) count++;
    return count;
}

// O(nlogn) time | O(1) space
int solve(vector<int>& a) {
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < a.size(); ){
        int element = a[i], equal_element = 0;
        while(element == a[i]){
            equal_element++, i++;
        }
        if(i < a.size() and a[i] == element + 1) ans += equal_element;
    }
    return ans;
}
