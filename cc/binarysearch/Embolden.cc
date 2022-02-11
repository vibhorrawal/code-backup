// O(PATTERN * (LONGEST_PATTERN + TEXT)) time | O(TEXT) space   
string solve(string text, vector<string>& patterns) {
    int n = text.size(), f;
    vector<bool> found(n);
    for(string p : patterns){
        f = 0;
        while(1){
            f = text.find(p, f);
            if(f == -1) break;
            for(int pos = 0; pos < p.size(); pos++){
                found[f + pos] = true;
            }
            f++;
        }
    }
    string res, b = "<b>", bt = "</b>";
    for(int i = 0; i < n;){
        if(not found[i]) res += text[i++];
        else{
            res += b;
            while(found[i]) {
                res += text[i++];
            }
            res += bt;
        }
    }
    return res;
}