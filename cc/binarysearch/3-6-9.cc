// O(nlogn) time | O(n) space
bool contain(int n){
    while(n){
        int r = n % 10;
        if(r == 3 || r == 6 || r == 9)
            return true;
        n /= 10;
    }
    return false;
}
vector<string> solve(int n) {
    vector<string> res;
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 || contain(i)) res.push_back("clap");
        else res.push_back(to_string(i));
    }
    return res;
}
