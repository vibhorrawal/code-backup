// O(NlogN) time | O(1) space
// greedily choosing
int solve(vector<int>& weights, int limit) {
    if(weights.size() < 2) return weights.size();
    sort(weights.begin(), weights.end());
    int ans = 0, l = 0, r = weights.size()-1;
    while(l <= r){
        if(l == r){
            ans++;
            break;
        }
        if(weights[l] + weights[r] <= limit){
            l++;
            r--;
            ans++;
        }
        else{
            r--;
            ans++;
        }
    }
    return ans;
}