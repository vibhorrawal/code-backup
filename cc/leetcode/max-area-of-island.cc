class Solution {
    vector<vector<int>> v;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    
    int dfs(int x, int y){
        int count = 1;
        v[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi < 0 || xi >= v.size() || yi < 0 || yi >= v[0].size())
                continue;
            if(v[xi][yi] == 1)
                count += dfs(xi,yi);
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        v = grid;
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                if(v[i][j] == 1)
                    ans = max(ans, dfs(i,j));
            }
        }
        return ans;
    }
};
