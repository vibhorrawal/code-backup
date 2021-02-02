// O(N) time | O(1) space
int solve(vector<int>& prices) {
    int minp = INT_MAX, maxprofit = 0;
    for(int p : prices){
        minp = min(p, minp);
        maxprofit = max(p - minp, maxprofit);
    }
    return maxprofit;
}
