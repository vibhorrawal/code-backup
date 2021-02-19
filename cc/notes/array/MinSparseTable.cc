#include<bits/stdc++.h>
using namespace std;

class MinSparseTable {
    int N, P; // P is max power of 2 needed
    vector<int> log2;
    vector<vector<int>> dp;

// Index Table (IT) associated with the values in the sparse table. This table
// is only useful when we want to query the index of the min (or max) element
// in the range [l, r] rather than the value itself. The index table doesn’t
// make sense for most other range query types like gcd or sum.
    vector<vector<int>> it;

public:
    MinSparseTable(vector<int> values){
        N = values.size();
        P = (int)(log(N) / log(2));
        dp = vector<vector<int>>(P + 1, vector<int>(N));
        it = vector<vector<int>>(P + 1, vector<int>(N));
        log2 = vector<int>(N + 1);

        for (int i = 0; i < N; i++) {
            dp[0][i] = values[i];
            it[0][i] = i;
        }

        for (int i = 2; i <= N; i++) {
            log2[i] = log2[i / 2] + 1;
        }

        for (int p = 1; p <= P; p++) {
            for (int i = 0; i + (1<<p) <= N; i++) {
                int left_interval = dp[p-1][i];
                int right_interval = dp[p-1][i + (1 << (p - 1))];
                dp[p][i] = min(left_interval, right_interval);

                if(left_interval <= right_interval){
                    it[p][i] = it[p-1][i];
                }
                else {
                    it[p][i] = it[p-1][i + (1 << (p - 1))];
                }
            }
        }
    }

    // O(1) as min has no issue with overlapping, but this is not the case with sum, multiply
    int query_min(int l, int r){
        int len = r - l + 1;
        int p = log2[len];
        int k = 1 << p;
        return min(dp[p][l], dp[p][r - k + 1]);
    }

    int query_min_index(int l, int r){
        int len = r - l + 1;
        int p = log2[len];
        int k = 1 << p;
        int left_interval = dp[p][l];
        int right_interval = dp[p][r - k + 1];
        if(left_interval <= right_interval) return it[p][l];
        return it[p][r - k + 1];
    }
};

int32_t main(int argc, char const *argv[]){
    MinSparseTable st({1,2,-3,2,4,-1,5});

    cout << st.query_min(1, 5) << endl;
    cout << st.query_min_index(1, 5) << endl;

    cout << st.query_min(3, 3) << endl;
    cout << st.query_min_index(3, 3) << endl;

    cout << st.query_min(3, 6) << endl;
    cout << st.query_min_index(3, 6) << endl;

    return 0;
}
