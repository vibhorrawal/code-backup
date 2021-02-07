// all pair shortest path in O(V^3)
// can detect negatie weight cycles

// better use adjacency matrix instead of list

const int INF = 1e9 + 5;
vector<vector<int>> floyd(vector<vector<int>> &adj_matrix){
    const int n = adj_matrix.size();
    vector<vector<int>> dist = adj_matrix;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}
