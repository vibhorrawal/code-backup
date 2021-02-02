bool solve(string s, string p) {
    map<char,string> p2s;
    map<string,char> s2p;
    stringstream ss(s);
    int i = 0;
    string t;
    while(getline(ss, t, ' ')){
        char pc = p[i++];
        string sc = t;
        if(s2p.count(sc) || p2s.count(pc)){
            if(s2p[sc] != pc) return false;
            if(p2s[pc] != sc) return false;
        }
        else{
            s2p[sc] = pc;
            p2s[pc] = sc;
        }
    }
    return i == p.size();
}
