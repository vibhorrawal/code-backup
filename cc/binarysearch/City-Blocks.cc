// O(NM + size_of_list) time | O(MN) space
int solve(vector<vector<string>>& matrix, vector<string>& blocks) {
    map<string,int> x,y;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            string c = matrix[i][j];
            x[c] = i;
            y[c] = j;
        }
    }
    int cost = 0, dx = 0, dy = 0;
    for(string c : blocks){
        cost += abs(dx - x[c]) + abs(dy - y[c]);
        dy = y[c];
        dx = x[c];
    }
    return cost;
}
