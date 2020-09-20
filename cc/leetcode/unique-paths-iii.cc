// O(4 ^ (mn)) time | O(mn) space
class Solution {
    vector<vector<int>> grid;
    pair<int,int> target;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int path;
    void dfs(int x, int y, int steps){
        if(grid[x][y] == 2 && steps == 0){
            path++;
            return;
        }
        int val = grid[x][y];
        grid[x][y] = -2;
        for(int i = 0; i < 4; i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            
            if(xi < 0 || xi >= grid.size() || yi < 0 || yi >= grid[0].size())
                continue;
            
            if(grid[xi][yi] < 0)
                continue;
            
            dfs(xi,yi, steps-1);
        }
        grid[x][y] = val;
        return;
    }
public:
    int uniquePathsIII(vector<vector<int>>& v) {
        grid = v;
        path = 0;
        pair<int,int> s = {-1,-1};
        int len = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) s = {i,j};
                if(grid[i][j] == 2) target = {i,j};
                if(grid[i][j] == 0) len++;
            }
        }
        if(s.first == -1 || target.first == -1)
            return 0;
        
        dfs(s.first, s.second, len+1);
        return path;
    }
};
