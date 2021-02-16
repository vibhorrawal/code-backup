#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
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
#define db(...) if(0) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

/*
q[i]=p[i]^(i%1)^(i%2)^...^(i%n)

Q = q[1]^q[2]^...^q[n] = (p[1]^...^p[n]) ^ (^ for i=1..n for k=1..n (i%k))

= (p[1]^...^p[n]) ^ (^ for k=1..n for i=1..n (i%k)). Let P=p[1]^...^p[n]. So,

Q = P ^ (^ for k=1..n for i=1..n (i%k)).

Now we have to calculate these xors

for all k: (^ for i=1..n (i%k)). ^ for i=1..n (i%k) = 0^1^2^...^(k-1) ^ 0^1^2^...^(k-1) ^ ... ^ 0^1^2^...^(k-1) [(n/k) times] ^ 0^1^2...^(n%k)

= ((n/k)%2)*(0^1^2^...^(k-1)) ^ (0^1^2...^(n%k)).

We can pre-calculate all xor sums like (0^1^2^...^(k-1)).

using a precalculated array X[1..n] with X[i] as 1^2^..^i

for( int i = 1 ; i <= N ; ++i ) F[ i ] = F[ i-1 ] ^ i; The rest is obvious
*/

int32_t main(int argc, char const *argv[]){
    fastIO;
    int n;
    cin>>n;
    vi p(n);
    read(p);
    vi f(n + 1);

    int ans = 0;
    for (int num = 1; num <= n; num++) {
        f[num] = f[num-1] ^ num;
    }
    REP(i,n) {
        int num = i + 1;
        int quo = n / num, rem = n % num;
        ans ^= f[rem];
        ans ^= p[i];
        if(quo % 2 == 1) ans ^= f[num-1];
    }

    cout << ans << endl;
    return 0;
}


int xorUpToK(int k) {
	switch (k % 4) {
		case 0: return k;
		case 1: return 1;
		case 2: return k + 1;
		case 3: return 0;
	}
    return -1;
}
