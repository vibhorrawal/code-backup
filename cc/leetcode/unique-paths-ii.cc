// O(mn) time | O(mn) space
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1])
            return 0;
        vector<vector<int>> paths(n, vector<int> (m, 0));
        paths[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && !(!i && !j))
                    paths[i][j] = (i > 0 ? paths[i-1][j] : 0) + 
                                  (j > 0 ? paths[i][j-1] : 0);
                else if(grid[i][j] == 1)
                    paths[i][j] = 0;
            }
        }
        return paths[n-1][m-1];
    }
};

// clearer ->
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1])
            return 0;
        vector<vector<int>> paths(n, vector<int> (m, 0));
        paths[0][0] = 1;
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0)
                paths[i][0] = 1;
            else
                break;
        }
        for(int i = 0; i < m; i++){
            if(grid[0][i] == 0)
                paths[0][i] = 1;
            else
                break;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(grid[i][j] == 0)
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
                else
                    paths[i][j] = 0;
            }
        }
        return paths[n-1][m-1];
    }
};