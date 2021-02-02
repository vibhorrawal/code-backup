// O(n * logn) time and space | max n times we need to insert which is O(logn)
int solve(vector<int>& cells) {
    multiset<int, greater<int>> s;
    for(int i : cells) s.insert(i);
    while(s.size() > 1){
        int a = *s.begin(); s.erase(s.find(a));
        int b = *s.begin(); s.erase(s.find(b));
        if(a == b) continue;
        s.insert((a+b)/3);
    }
    return s.size() ? *s.begin() : -1;
}
