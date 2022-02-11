// O(N) time | O(1) space
int solve(string numeral) {
    map<char,int> mp = {
    { 'M', 1000 },
    { 'D', 500 },
    { 'C', 100 },
    { 'L', 50 },
    { 'X', 10 },
    { 'V', 5 },
    { 'I', 1 }
};
    int n = 0, i = 0;
    while(i < numeral.size()){
        if(i + 1 < numeral.size() && mp[numeral[i]] < mp[numeral[i+1]]){
            n += mp[numeral[i+1]] - mp[numeral[i]];
            i+= 2;
        }
        else n += mp[numeral[i++]];
    }
    return n;
}