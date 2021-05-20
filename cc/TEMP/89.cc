#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<pii>> vvp;
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define endl char(10)
#define pb emplace_back
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#ifdef LOCAL
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define db(...) {}
#endif

// long stockAnalysis(vector<int> stockValue) {
//     long max_untill = INT_MIN, max_val = INT_MIN, ans = INT_MIN;
//     for(int val : stockValue){
//         if(max_untill != INT_MIN and max_untill + val < 0){
//             ans = max(ans, max_val * max_untill);
//         }
//         max_untill += val;
//         max_val = max(max_val, (long) val);
//         if(max_untill < 0){
//             max_val = INT_MIN;
//             max_untill = 0;
//         }
//     }
//     return ans;
// }

void construct_segment_tree(vector<int>& segtree,
                            vector<int>& a, int n)
{
    // assign values to leaves of the segment tree
    for (int i = 0; i < n; i++)
        segtree[n + i] = a[i];

    /* assign values to internal nodes
    to compute maximum in a given range */
    for (int i = n - 1; i >= 1; i--)
        segtree[i] = max(segtree[2 * i],
                         segtree[2 * i + 1]);
}

// void update(vector<int>& segtree, int pos, int value,
//             int n)
// {
//     // change the index to leaf node first
//     pos += n;
//
//     // update the value at the leaf node
//     // at the exact index
//     segtree[pos] = value;
//
//     while (pos > 1) {
//
//         // move up one level at a time in the tree
//         pos >>= 1;
//
//         // update the values in the nodes in
//         // the next higher level
//         segtree[pos] = max(segtree[2 * pos],
//                            segtree[2 * pos + 1]);
//     }
// }
//
int range_query(vector<int>& segtree, int left, int
                                                    right,
                int n)
{
    /* Basically the left and right indices will move
        towards right and left respectively and with
        every each next higher level and compute the
        maximum at each height. */
    // change the index to leaf node first
    left += n;
    right += n;

    // initialize maximum to a very low value
    int ma = INT_MIN;

    while (left < right) {

        // if left index in odd
        if (left & 1) {
            ma = max(ma, segtree[left]);

            // make left index even
            left++;
        }

        // if right index in odd
        if (right & 1) {

            // make right index even
            right--;

            ma = max(ma, segtree[right]);
        }

        // move to the next higher level
        left /= 2;
        right /= 2;
    }
    return ma;
}

long stockAnalysis(vector<int> s) {
    vector<long> pre;
    pre.push_back(0);
    int n = s.size();
    for(int x : s) pre.push_back(pre.back() + x);
    vector<int> segtree(2 * n);
    construct_segment_tree(segtree, s, n);

    long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(j < i) continue;
            long sum = pre[j+1] - pre[i];
            int mx = range_query(segtree, i, j + 1, n);
            ans = max(ans, mx * sum);
        }
    }
    return ans;
}
int32_t main(int argc, char const *argv[]){
    fastIO;
    auto v = stockAnalysis({2,-3,8,-2,5});
    db(v);
    return 0;
}
