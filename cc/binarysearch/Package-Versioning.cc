bool solve(string older, string newer) {
    vector<int> o,n;
    stringstream oo(older), nn(newer);
    string t;
    while(getline(oo, t, '.')) o.push_back(stoi(t));
    while(getline(nn, t, '.')) n.push_back(stoi(t));
    bool flag = false;
    for(int i = 0; i < min(o.size(), n.size()); i++){
        if(o[i] < n[i]) return true;
        if(o[i] > n[i]) return false;
        // if(n[i] > o[i]) flag = true;
    }
    return false;
}

// a better way to compare
bool solve(string older, string newer) {
    vector<int> o,n;
    stringstream oo(older), nn(newer);
    string t;
    while(getline(oo, t, '.')) o.push_back(stoi(t));
    while(getline(nn, t, '.')) n.push_back(stoi(t));
    return n > o;
}

bool solve(string older, string newer) {
    vector<int> o,n;
    replace(older.begin(), older.end(), '.', ' ');
    replace(newer.begin(), newer.end(), '.', ' ');
    stringstream oo(older), nn(newer);
    int t;
    while(oo >> t) o.push_back(t); // behaves as cin stream
    while(nn >> t) n.push_back(t);
    return n > o;
}
