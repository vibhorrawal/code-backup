#include<bits/stdc++.h>
#include<cassert>
using namespace std;

// this is TSP with DP, iterative
// O(N^2 * 2 ^ N)

class TSPsolver {
    const int INF = 1e9 + 5;

    int N, src;
    vector<vector<int>> dist;
    vector<int> tour;
    long long min_tour_cost = INF;
    vector<vector<long long>> memo;
    bool solved = false;

    bool not_in(int element, int set){
        return ((1 << element) & set) == 0;
    }

    vector<int> combinations(int r, int n){
        vector<int> subsets;
        combinations(0,0,r,n,subsets);
        return subsets;
    }

    void combinations(int set, int at, int r, int n, vector<int> &subsets){
        int elements_to_pick = n - at;
        if(elements_to_pick < r) return;

        if(r == 0) {
            subsets.push_back(set);
            return;
        }

        for(int i = at; i < n; i++){
            set ^= 1<<i;
            combinations(set, i + 1, r - 1, n, subsets);
            set ^= 1<<i;
        }
    }

    void solve(){
        if(solved) return;
        int END_STATE = (1<<N) - 1;
        memo = vector<vector<long long>>(N, vector<long long>(1<<N));

        for (int end = 0; end < N; end++) {
            if(end == src) continue;
            memo[end][(1<<src) | (1<<end)] = dist[src][end];
        }

        for (int r = 3; r <= N; r++) {
            for(int subset : combinations(r, N)){
                if(not_in(src, subset)) continue;

                for (int next = 0; next < N; next++) {
                    if(next == src or not_in(next, subset)) continue;
                    int subset_without_next = subset ^ (1<<next);
                    long long mindist = INF;

                    for (int end = 0; end < N; end++) {
                        if(end == src or end == next or not_in(end, subset)) continue;
                        long long newdist = memo[end][subset_without_next] + dist[end][next];
                        mindist = min(mindist, newdist);

                    }
                    memo[next][subset] = mindist;
                }
            }
        }

        // connect tour back to starting node
        for(int i = 0; i < N; i++){
            if(i == src) continue;
            long long tour_cost = memo[i][END_STATE] + dist[i][src];
            min_tour_cost = min(tour_cost, min_tour_cost);
        }

        solved = true;
    }
public:
    TSPsolver(vector<vector<int>> &dist) : TSPsolver(0, dist) { }
    TSPsolver(int src, vector<vector<int>> &dist) {
        this->dist = dist;
        this->src = src;
        N = dist.size();

        assert(2 < N and N < 32);
        assert(0 <= src and src < N);
        assert(N == (int) dist[0].size());
    }

    long long get_tour_cost(){
        if(not solved) solve();
        return min_tour_cost;
    }

    vector<int> get_tour(){
        if(not solved) solve();
        if(tour.size()) return tour; // solved already
        int END_STATE = (1<<N) - 1;
        int last_index = src;
        int state = END_STATE;
        tour.push_back(src);

        for (int i = 1; i < N; i++) {
            int best_index = -1;
            long long best_distance = INF;
            for (int j = 0; j < N; j++) {
                if(j == src or not_in(j, state)) continue;
                long long newdist = memo[j][state] + dist[j][last_index];
                if(newdist < best_distance) {
                    best_index = j;
                    best_distance = newdist;
                }
            }
            tour.push_back(best_index);
            state ^= (1<<best_index);
            last_index = best_index;
        }
        tour.push_back(src);
        reverse(tour.begin(), tour.end());
        return tour;
    }
};

//------------------------------------------------------------------------------
// O(N!)
class TSPBruteForce {
private:
    const int INF = 1e9 + 5;

    int N, src;
    vector<vector<int>> dist;
    vector<int> tour;
    long long min_tour_cost = INF;
    bool solved = false;

    long long cost(vector<int> &path){
        long long tour_cost = 0;
        for (int r = 0; r < path.size()-1; r++) {
            tour_cost += dist[path[r]][path[r+1]];
        }
        return tour_cost;
    }

    void solve(){
        if(solved) return;
        vector<int> path;
        path.push_back(src);
        for(int i = 0; i < N; i++) {
            if(i == src) continue;
            path.push_back(i);
        }
        path.push_back(src);
        auto b = path.begin() + 1;
        auto e = --path.end();
        do {
            long long tour_cost = cost(path);
            if(tour_cost < min_tour_cost) {
                min_tour_cost = tour_cost;
                tour = path;
            }
        } while(next_permutation(b,e));

        solved = true;
    }

public:
    TSPBruteForce(vector<vector<int>> &dist) : TSPBruteForce(0, dist) {}
    TSPBruteForce(int src, vector<vector<int>> &dist) {
        this-> src = src;
        this->dist = dist;
        N = dist.size();
        assert(2 < N and N < 32);
        assert(0 <= src and src < N);
        assert(N == (int) dist[0].size());
    }

    vector<int> get_tour(){
        if(not solved) solve();
        return tour;
    }

    int get_tour_cost(){
        if(not solved) solve();
        return min_tour_cost;
    }
};

int32_t main(int argc, char const *argv[]){
    int n = 6, INF = 1e9 + 5;
    vector<vector<int>> g(n, vector<int> (n, INF));
    for(int i = 0; i < n; i++) g[i][i] = 0;
    g[5][0] = 10;
    g[1][5] = 12;
    g[4][1] = 2;
    g[2][4] = 4;
    g[3][2] = 6;
    g[0][3] = 8;

    TSPsolver solver = TSPsolver(0, g);
    cout << solver.get_tour_cost() << endl; // 42

    // Prints: [0, 3, 2, 4, 1, 5, 0]
    for(int d : solver.get_tour()) cout<<d<<' '; cout<<endl;

    TSPBruteForce solver2 = TSPBruteForce(0, g);

    assert(solver.get_tour_cost() == solver2.get_tour_cost());
    assert(solver.get_tour() == solver2.get_tour());

    //------------------------------------------------
    assert(false && "this assert fails");
    return 0;
}
