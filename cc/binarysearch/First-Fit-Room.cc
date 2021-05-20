// O(N) time | O(1) space
int solve(vector<int>& rooms, int target) {
    for(int &room : rooms){
        if(room >= target) return room;
    }
    return -1;
}


// alternate
int target;
bool greater_than(int value){
    return value >= target;
}
int solve(vector<int>& rooms, int target_) {
    target = target_;
    auto it = find_if(rooms.begin(), rooms.end(), greater_than);
    return it == rooms.end() ? -1 : *it;
}
