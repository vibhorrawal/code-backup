// O(N * LENGTH_OF_STRING) time | O(N) space
bool solve(vector<string>& orders) {
    unordered_set<int> picked, delivered;
    int id;
    for(string order : orders) {
        switch(order[0]) {
            case 'P':
                id = stoi(order.substr(1));
                if(delivered.count(id) or picked.count(id)) return false;
                picked.insert(id);
                break;
            case 'D':
                id = stoi(order.substr(1));
                if(!picked.count(id) or delivered.count(id)) return false;
                delivered.insert(id);
                break;
            default:
                assert(false);
        }
    }
    return picked.size() == delivered.size();
}