// when there are negative edges dijkstra can be stuck in infinite loop, use bellman_ford
// we relax V-1 times, and then check for the next time, if there are still updates,
// that means there are negative weight cycles

// O(VE) time
const int INF = 1e9 + 5;

// with adjacency list
vector<int> bellman_ford(vector<vector<pair<int,int>>> &g, int src, int V){
    int n = V;
    vector<int> dist(V, INF);
    dist[src] = 0;
    for(int i = 0; i < V-1; i++){
        for(int u = 0; u < n; u++){
            for(auto it : g[u]){
                int v = it.first, w = it.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // check again for negative cycles
    bool neg_cycle = false;
    for(int u = 0; u < n; u++){
        for(auto it : g[u]){
                int v = it.first, w = it.second;
                if(dist[u] + w < dist[v]){
                    neg_cycle = true;
                }
            }
    }

    return dist;
}

// with edge list
vector<int> bellman_ford(vector<vector<int>> &edges, int src, int V){
    vector<int> dist(V, INF);
    dist[src] = 0;
    for(int i = 0; i < V-1; i++){
        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    // check again for negative cycles
    bool neg_cycle = false;
    for(auto edge : edges){
        int u = edge[0], v = edge[1], w = edge[2];
        if(dist[u] + w < dist[v]){
            neg_cycle = true;
        }
    }
    assert(not neg_cycle);
    return dist;
 }
