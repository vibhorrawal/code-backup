// greedy
// O(1)
int solve(int n) {
    int coins[] = {1,5,10,25};
    int i = 3, ans = 0;
    while(i >= 0){
        while(n - coins[i] >= 0) {
            int s = n/coins[i];
            ans += s;
            n = n % coins[i];
        }
        i--;
    }
    return ans;
}
