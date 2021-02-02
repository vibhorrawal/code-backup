bool possible;
void dec(vector<int> &v){
    for(int i = 1; i < v.size(); i++){
        if(v[i] != v[i-1] - 1)
            return;
    }
    possible = true;
}
void check(string s, vector<int> v){
    // cout<<s.size()<<endl;
    if(s.size()){
        v.push_back(stoi(s));
        dec(v);
        v.pop_back();
        // for(int i : v) cout<<i<<' ';
        // cout<<endl;
        // return;
    }
    for(int i = 1; i < min((int) s.size(), 6); i++){
        v.push_back(stoi(s.substr(0, i)));
        check(s.substr(i), v);
        v.pop_back();
    }
}
bool solve(string s) {
    vector<int> v;
    possible = false;
    for(int i = 1; i < min((int) s.size(), 6); i++){
        // cout<<i<<' '<<s.substr(0,i)<<' '<<s.substr(i)<<endl;
        v.push_back(stoi(s.substr(0, i)));
        check(s.substr(i), v);
        v.pop_back();
    }
    return possible;
}



////////////// cleaner code
// O(n^2) time | O(n) space
vector<int> v;
bool possible;

void check(){
    if(v.size() < 2) return;
    for(int i = 0; i < v.size()-1; i++){
        if(!(v[i] == v[i+1] + 1)) return;
    }
    // for(int x : v) cout << x << ' '; cout<<endl;
    possible = true;
}
void backtrack(const string &s, int pos){
    if(pos >= s.size()){
        check();
        return;
    }
    for(int sz = 1; sz <= s.size() - pos; sz++){
        int integer = stoi(s.substr(pos, sz));
        v.push_back(integer);
        backtrack(s, pos + sz);
        v.pop_back();
    }
}
bool solve(string s) {
    v.clear();
    possible = false;
    backtrack(s, 0);
    return possible;
}
