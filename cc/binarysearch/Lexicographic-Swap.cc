string solve(string s) {
    string t = s;
    sort(t.begin(), t.end());
    // cout<<s<<endl<<t<<endl;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]){
            int it = s.find_last_of(t[i]);
            // cout<<it;
            swap(s[i], s[it]);
            break;
        }
    }
    return s;
}

// O(nlogn) time | O(n) space
string solve(string s) {
    string t = s;
    sort(t.begin(), t.end());
    int i = 0;
    while(i < s.size() and s[i] == t[i]) i++;
    if(i == s.size()) return s;
    char lower = t[i], higher = s[i];
    s[i] = lower;
    i = s.size()-1;
    while(s[i] != lower) i--;
    s[i] = higher;
    return s;
}

// O(n) time | O(1) space | smarter way
string solve(string s) {
    int break_point = 0;
    while(break_point+1 < s.size() and s[break_point] <= s[break_point+1])
        break_point++;
    // if(break_point == s.size()-1) return s;

    int minimum_char_idx = break_point;
    for(int i = break_point; i < s.size(); i++){
        if(s[minimum_char_idx] >= s[i]){
            minimum_char_idx = i;
        }
    }
    for(int i = 0; i < minimum_char_idx; i++){
        if(s[i] > s[minimum_char_idx]){
            swap(s[i], s[minimum_char_idx]);
            break;
        }
    }
    return s;
}
