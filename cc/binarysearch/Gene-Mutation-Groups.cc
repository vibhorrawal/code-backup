// O(N) time and space
vector<int> parent;

int find(int i){
    if(parent[i] == -1) return i;
    return parent[i] = find(parent[i]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    // cout<<"a,b: "<<a<<' '<<b<<endl;
    if(a == b) return;
    parent[a] = b;
}

int mapper(string &s, int &mpc, unordered_map<string,int> &mp){
    if(mp.count(s)) return mp[s];
    return mp[s] = mpc++;
}

int solve(vector<string>& a) {
    unordered_map<string,int> mp;
    int mpc = 1, sz = a[0].size();
    parent = vector<int> (1e5, -1);
    for(string &s : a){
        for(int i = 0; i < sz; i++){
            char t = s[i];
            int rep = mapper(s,mpc,mp);
            for(char c : {'A','C','G','T'}){
                s[i] = c;
                // int tmp = mapper(s,mpc,mp);
                if(mp.count(s)) Union(rep, mapper(s,mpc,mp));
                // cout<<s<<endl;
                // Union(rep, mapper(s,mpc,mp));
            }
            s[i] = t;
        }
    }
    set<int> se;
    for(string &s : a) {
        // cout<<parent[i]<<' ';
        se.insert(find(mapper(s,mpc,mp)));
    }
    return se.size();
}
