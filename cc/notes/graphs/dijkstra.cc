// one way is like this: from leetcode https://leetcode.com/problems/network-delay-time/
class Solution {
    int min_dist(vector<int> &dist, vector<bool> &incl){
        int mini = -1, minv = INT_MAX;
        for(int i = 1; i < dist.size(); i++){
            if(minv >= dist[i] && !incl[i]){
                mini = i;
                minv = dist[i];
            }
        }
        return mini;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> wt(N+1, vector<int>(N+1, -1));

        for(auto t: times){
            wt[t[0]][t[1]] = t[2];
        }

        vector<int> dist(N+1, 6001);
        dist[K] = 0;
        vector<bool> incl(N+1, false);
        for(int i = 0; i< N; i++){
            int u = min_dist(dist, incl);
            if(u == -1) break;
            incl[u] = true;
            for(int v = 1; v <= N; v++){
                if(!incl[v] && wt[u][v] != -1 && dist[u] + wt[u][v] < dist[v])
                    dist[v] = dist[u] + wt[u][v];
            }
        }
        // for(auto t: dist) cout<<t<<' ';
        int maxt = *max_element(dist.begin()+1, dist.end());
        return (maxt == 6001 ? -1: maxt);
    }
};

// but ^ this is utterly slow


// O(ElogV) time codes :-

// lazy dijkstra
const int INF = 1e9 + 5;
vector<int> dijkstra(vector<vector<pair<int,int>>> g, int src, int n){
    vector<int> dist(n, INF);
    vector<int> parent(n, -1); // to reconstruct path
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while(pq.size()){
        auto it = pq.top(); pq.pop();
        int w = it.first, u = it.second;
        if(dist[u] < w) continue;
        for(auto p : g[u]){
            int v = p.first, wt = p.second;
            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[u], v});
                parent[v] = u;
            }
        }
    }
    return dist;
}

// Eager dijkstra
// here use indexed priority_queue, but I have used set
vector<int> dijkstra(vector<vector<pair<int,int>>> g, int src, int n){
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    set<pair<int,int>> s;
    dist[src] = 0;
    s.insert({dist[src], src});

    while(s.size()){
        auto it = s.begin();
        int w = it->first, u = it->second;
        s.erase(it);
        if(dist[u] < w) continue;
        for(auto p : g[u]){
            int v = p.first, wt = p.second;
            if(dist[u] + wt < dist[v]) {
                auto it = s.find({dist[v], v});
                if(it != s.end()) s.erase(it);

                dist[v] = dist[u] + wt;
                s.insert({dist[u], v});
                parent[v] = u;
            }
        }
    }
    return dist;
}

// testing on small and large dataset almost gave same running time,
// hence if you want to use Eager dijkstra use indexed priority queue, not ordered set
