class Solution {
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    vector<vector<char>> grid;
    
    void dfs(int x, int y){
        grid[x][y] = '0';
        for(int i = 0; i < 4; i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi < 0 || xi >= grid.size() || yi < 0 || yi >= grid[0].size())
                continue;
            if(grid[xi][yi] == '1')
                dfs(xi, yi);
        }
    }
public:
    int numIslands(vector<vector<char>>& g) {
        grid = g;
        int count  = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
