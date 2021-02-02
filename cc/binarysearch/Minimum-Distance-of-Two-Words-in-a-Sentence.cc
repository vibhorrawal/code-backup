// O(n) time and space
int solve(string text, string word0, string word1) {
    vector<int> v;
    stringstream ss(text);
    string t;
    while(getline(ss, t, ' ')){
        if(t == word0) v.push_back(0);
        else if(t == word1) v.push_back(1);
        else v.push_back(-1);
    }
    // for(int i : v) cout<<i<<' ';
    int mind = INT_MAX;
    int last0 = -1, last1 = -1;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == -1) continue;
        if(v[i] == 1){
            if(last0 != -1)
                mind = min(mind, i - last0 - 1);
            last1 = i;
        }
        else{
            if(last1 != -1)
                mind = min(mind, i - last1 - 1);
            last0 = i;
        }
    }
    return mind == INT_MAX ? -1 : mind;
}
