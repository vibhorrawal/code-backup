// O(N) time 
const int M = 1e9 + 7;

long inline calc(long count){
    count += 1;
    return count * (count - 1) / 2;
}

int solve(string s) {
    long ans = 0, count = 0;
    for(char c : s){
        if(c == '0'){
            ans += calc(count);
            count = 0;
        }
        else count++;
        ans %= M;
    }
    ans += calc(count);
    ans %= M;
    return ans;
}