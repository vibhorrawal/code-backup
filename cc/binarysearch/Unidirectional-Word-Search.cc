// O(NM * W) time | O(1) space
vector<vector<string>> board;
string word;
bool horizontal(int r, int c){
    int i = 0;
    while(r+i < board.size() && i < word.size() && board[r+i][c] == string(1,word[i])) i++;
    cout<<i<<endl;
    return i == word.size();
}
bool vertical(int r, int c){
    int i = 0;
    while(c+i < board[0].size() && i < word.size() && board[r][c+i] == string(1,word[i])) i++;
    return i == word.size();
}
bool solve(vector<vector<string>>& b, string w) {
    board = b;
    word = w;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            // cout<<board[i][j]<<' '<<string(1,word[0])<<endl;
            if(board[i][j] == string(1,word[0])){
                // cout<<"test";
                if(horizontal(i,j) || vertical(i,j))
                    return true;
            }
        }
    }
    return false;
}

// cleaner
// O((N + W) * M + (M + W) * N) time | O(N + M) space
bool solve(vector<vector<string>>& b, string w) {
    for(int r = 0; r < b.size(); r++){
        string s;
        for(int c = 0; c < b[0].size(); c++) s += b[r][c];
        if(s.find(w) != -1) return true;
    }

    for(int c = 0; c < b[0].size(); c++){
        string s;
        for(int r = 0; r < b.size(); r++) s += b[r][c];
        if(s.find(w) != -1) return true;
    }
    return false;
}
