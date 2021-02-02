// O(N) time | O(1) space
bool solve(string s, int k) {
    int i = 0;
    while(i < s.size() && s[i] == '.') i++;
    if(i >= k)
        return true;

    int start = i;
    i = s.size()-1;
    while(i >= 0 && s[i] == '.') i--;
    if(s.size()-i-1 >= k)
        return true;

    int end = i, count = 0;
    for(int i = start; i <= end; i++){
        if(s[i] == '.') count++;
        else count = 0;
        if(count >= k * 2-1) return true;
    }
    return false;
}

// O(Nk) time | O(1) space
bool solve(string s, int k) {
    for(char &c : s) if(c == '.') c = '1';
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'x'){
            for(int j = 1; j < k; j++){
                if(i+j < s.size() && s[i+j] != 'x')
                    s[i+j] = '2';
                if(i-j >= 0 && s[i-j] != 'x')
                    s[i-j] = '2';
            }
        }
    }
    // for(char c : s) cout<<c<<' ';
    for(char c : s) if(c == '1') return true;
    return false;
}

// elegant
// O(N) time and space
bool solve(string s, int k) {
    vector<int> v(s.size());
    v[0] = s[0] == 'x' ? 0 : 1e9;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'x') v[i] = 0;
        else v[i] = v[i-1] + 1;
    }
    for(int i = s.size()-2; i >= 0; i--){
        v[i] = min(v[i], v[i+1] + 1);
    }
    for(int x : v) if(x >= k) return true;
    return false;
}

// O(N) time | O(1) space
bool solve(string s, int k) {
    bool is_possible = true;
    int pos = 0, cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'x'){
            if(i - pos >= k and is_possible) return true;
            else is_possible = false;
            cnt = 0;
        }
        else{
            cnt++;
            if(not is_possible and cnt >= k) {
                pos = i;
                is_possible = true;
            }
        }
    }
    return is_possible;
}

// another elegant way
bool solve(string s, int k) {
    int i = 0;
    while(i < s.size() and s[i] == '.') i++;
    if(i >= k) return true;
    i = s.size()-1;
    while(i >= 0 and s[i] == '.') i--;
    if(s.size() - i -1 >= k) return true;
    string check(2 * k - 1, '.');
    return s.find(check) != -1;
}
