// O(n * m) time | O(n) space; n is size of smallest word, m is size of list
string solve(vector<string>& words) {
    int c = 0;
    while(1){
        for(int i = 1; i < words.size(); i++){
            if(words[i][c] != words[i-1][c] || words[i-1].size() <= c) {
                return words[0].substr(0,c);
            }
        }
        c++;
    }

}

// sort and check first and last string for common
// O(m log nm) time | O(n) sapce
string solve(vector<string>& w) {
    sort(w.begin(), w.end(), [](const string &a, const string &b){
        // if(a.size() == b.size()){
            return a < b;
        // }
        // return a.size() < b.size();
    });
    int c = 0;
    int l = w.size()-1;
    while(c < min(w[0].size(), w[l].size()) and w[0][c] == w[l][c]) c++;
    return w[0].substr(0,c);
}
