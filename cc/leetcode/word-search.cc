// O(mn*string_length) time | O(string_length) space
class Solution {
    vector<vector<char>> mat;
    string s;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    bool dfs(int pos, int x, int y, vector<vector<bool>> &vis){
        if(pos == s.size() || (pos == s.size()-1 && s[pos] == mat[x][y]))
            return true;
        if(mat[x][y] != s[pos])
            return false;
        
        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi < 0 || xi >= vis.size() || yi < 0 || yi >= vis[0].size())
                continue;
            if(!vis[xi][yi])
                if(dfs(pos+1, xi, yi, vis))
                    return true;
        }
        vis[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        s = word;
        mat = board;
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(0, i,j,vis))
                    return true;
            }
        }
        return false;
    }
};