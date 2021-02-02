// O(n) time and O(1) space
int solve(vector<int>& a) {
    if(a.size() <= 1) return 0;
    int curr = a[1] - a[0];
    int count = 0;
    for(int i = 1; i < a.size(); i++){
        int diff = a[i] - a[i-1];
        if(diff * curr < 0) {
            curr = diff;
            count++;
            // cout<<i;
        }
        if(diff == 0) curr = a[i+1] - a[i];
    }
    return count;
}
