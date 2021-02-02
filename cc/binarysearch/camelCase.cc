// O(size_of_word * N) time and space
string lower(string s){
    for(char &c : s) c = tolower(c);
    return s;
}
string solve(vector<string>& words) {
    string res;
    res += lower(words[0]);
    for(int i = 1; i < words.size(); i++){
        string t = words[i];
        res += toupper(t[0]);
        res += lower(t.substr(1));
    }
    return res;
}
