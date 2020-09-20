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