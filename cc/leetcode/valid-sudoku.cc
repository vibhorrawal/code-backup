// O(n^2) time | O(1) space
class Solution {
    bool invalid_row(vector<char> &row){
        vector<bool> present(10, false);
        for(char c: row){
            if(c == '.')
                continue;
            if(present[c-'0'])
                return true;
            present[c-'0'] = true;
        }
        return false;
    }
    
    bool invalid_col(int col, vector<vector<char>>& board){
        vector<bool> present(10, false);
        for(int i = 0; i < 9; i++){
            char c = board[i][col];
            if(c == '.')
                continue;
            if(present[c-'0'])
                return true;
            present[c-'0'] = true;
        }
        return false;
    }
    bool invalid_box(int b, vector<vector<char>>& board){
        vector<bool> present(10, false);
        int row = b / 3, col =  b % 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                char c = board[i+row*3][j+col*3];
                if(c == '.')
                    continue;
                if(present[c-'0'])
                    return true;
                present[c-'0'] = true;
            }
        }
        return false;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool invalid = false;
        for(auto row: board)
            invalid |= invalid_row(row);
        for(int i = 0; i < 9; i++)
            invalid |= invalid_col(i, board);
        for(int i = 0; i < 9; i++)
            invalid |= invalid_box(i, board);
        return !invalid;
    }
};