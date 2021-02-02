// O(NlogN) time | O(1) space
string solve(string s) {
    string vow = "aeiou";
    sort(s.begin(), s.end(), [&](char a, char b){
        if(vow.find(a) != string::npos){
            if(vow.find(b) != string::npos) return a < b;
            else return true;
        }
        else if(vow.find(b) != string::npos) return false;
        return a < b;
    });
    return s;
}

// O(N) time | O(1) space
string solve(string s) {
    int arr[26] = {0};
    for(char c : s) arr[c - 'a']++;
    string res;
    for(char c : {'a', 'e', 'i', 'o', 'u'}) {
        res += string(arr[c - 'a'], c);
        arr[c - 'a'] = 0;
    }
    for(char c = 'a'; c <= 'z'; c++){
        res += string(arr[c - 'a'], c);
    }
    return res;
}
