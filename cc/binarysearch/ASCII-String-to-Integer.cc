// O(N) time | O(1) space
int solve(string s) {
    int ans = 0, d = 0;
    for(char c : s){
        if(isdigit(c)){
            d = (d * 10) + c - '0';
        }
        else{
            ans += d;
            d = 0;
        }
    }
    return ans + d;
}