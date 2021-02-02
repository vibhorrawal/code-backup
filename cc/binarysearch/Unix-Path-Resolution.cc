// O(N) time and space, used stack
vector<string> solve(vector<string>& path) {
    vector<string> res;
    for(string s : path){
        if(s == ".") continue;
        if(s == "..") {
            if(res.size()) res.pop_back();
        }
        else res.push_back(s);
    }
    return res;
}
