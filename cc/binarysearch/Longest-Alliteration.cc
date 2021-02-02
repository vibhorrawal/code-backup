// O(n) time | O(1) space
int solve(vector<string>& words) {
    int maxl = 0, curr = 0;
    char prev = '#';
    for(string s : words){
        if(s[0] != prev){
            curr = 1;
            prev = s[0];
        }
        else curr++;
        maxl = max(maxl, curr);
    }
    return maxl;
}
