#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int n, k;
vi s(n), d(n);

inline double p(double t, int i){
  return s[i] * t + d[i];
}
double f(double t){
  double maxp = INT_MIN, minp = INT_MAX;
  for (int i = 0; i < n; i++) {
    double pi = p(t, i);
    maxp = max(pi, maxp);
    minp = min(pi, minp);
  }
  return maxp - minp;
}
double ternary_search(double l, double r) {
    double eps = 1e-9;
    while(r-l > eps){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 > f2) // for finding minimum, use > instead
            l = m1;
        else
            r = m2;
    }
    return min({f(l), f(r)});

}

int32_t main(int argc, char const *argv[]){
  fastIO;
  cin >> n >> k;
  s.resize(n);
  d.resize(n);
  REP(i,n) cin>>s[i]>>d[i];
  // find min f(t)
  // p(t) = s*t + d
  // f(t) = max(p(t)) - min(p(t))

  cout << fixed << setprecision(6) << ternary_search(0, k) << endl;
  return 0;
}
