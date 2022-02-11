// O(N) time | O(1) space
bool solve(vector<int>& a) {
    bool inc = true;
    if(a[0] > a[1]) return false;
    for(int i = 1; i < a.size(); i++){
        if(a[i-1] == a[i]) return false;
    }
    return true;
}