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
#define double long double

int n;
vi t,v;

double f(double tt){
  double minf = 1e15, maxf = 0;
  for (int i = 0; i < n; i++) {
    double d = (tt - t[i]) * (double) v[i];
    minf = min(d, minf);
    maxf = max(d, maxf);
  }
  assert(minf <= maxf);
  return maxf - minf;
}

double ternary_search(double l, double r){
  REP(c,100) {
    double m1 = (2*l + r)/3;;
    double m2 = (l + 2*r)/3;
    if(f(m1) > f(m2))
      l = m1;
    else
      r = m2;
  }
  return f(l);
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  while(cin>>n){
    if(n == 0) break;
    t.resize(n);
    v.resize(n);
    REP(i,n) cin>>t[i]>>v[i];
    cout << fixed << setprecision(6) << ternary_search(*max_element(t.begin(), t.end()), 1e15) << endl;
  }
  return 0;
}
