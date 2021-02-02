// O(N) time | O(1) space
bool solve(string a, string b, int k) {
    int diff = 0;
    for(int i = 0; i < b.size(); i++){
        if(a[i] > b[i]) diff += -a[i] + b[i] + 26;
        else diff += b[i] - a[i];
    }
    return diff <= k;
}
