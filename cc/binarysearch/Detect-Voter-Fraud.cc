// O(n) space and time
bool solve(vector<vector<int>>& votes) {
    // map<int,int> vote;
    // for(auto it : votes){
    //     if(vote.count(it[1])) if(vote[it[1]] != it[0]) return true;
    //     vote[it[1]] = it[0];
    // }
    set<int> s;
    for(auto it : votes) {
        if(s.count(it[1])) return true;
        s.insert(it[1]);
    }
    return false;
}
