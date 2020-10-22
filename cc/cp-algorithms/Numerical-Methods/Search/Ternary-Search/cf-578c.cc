// WA
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

int n;
vector<double> a;

double f(double x){
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(a[i] - x);
  }
  return ans;
}
double ternary_search(double l, double r){
  double eps = 1e-12;
  while(r-l > eps){
    double m1 = l + (r-l)/3;
    double m2 = r - (r-l)/3;
    if(f(m1) > f(m2))
      l = m1;
    else
      r = m2;
  }
  return r;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  cin>> n;
  a.resize(n);
  REP(i,n) cin>>a[i];
  // find x st a1-x, a2-x ... an-x is small
  double x = ternary_search(0, 10000);
  db(x);
  for (int i = 0; i < n; i++) {
    a[i] = a[i] - x;
  }
  double maximal = 0, minimal = 1e9;
  double sofar = 0;
  for (int i = 0; i < n; i++) {
    sofar += a[i];
    if(sofar < 0) sofar = 0;
    maximal = max(sofar, maximal);
  }
  sofar = 0;
  for (int i = 0; i < n; i++) {
    sofar += a[i];
    if(sofar > 0) sofar = 0;
    minimal = min(sofar, minimal);
  }
  cout << fixed<<setprecision(9)<<max(maximal, -minimal) << endl;
  return 0;
}
