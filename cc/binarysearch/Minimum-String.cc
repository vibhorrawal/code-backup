// O(n) time and space
int solve(string s, string t) {
    map<char,int> freq;
    for(char c : s) freq[c]++;
    int res = 0;
    for(char c : t){
        if(freq[c] == 0) res++;
        else{
            if(freq[c] == 1) freq.erase(freq.find(c));
            else freq[c]--;
        }
    }
    return res;
}
