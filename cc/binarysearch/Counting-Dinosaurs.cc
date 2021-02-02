// O(animals + dinosaurs) time | O(animals) space
int solve(string animals, string dinosaurs) {
    map<char,int> freq;
    for(char c : animals) freq[c]++;
    int res = 0;
    for(char c : dinosaurs) {
        res += freq[c];
        freq[c] = 0;
    }
    return res;
}

int solve(string animals, string dinosaurs) {
    unordered_set<char> d (dinosaurs.begin(), dinosaurs.end());
    int res = 0;
    for(char c : animals){
        res += d.count(c);
    }
    return res;
}
