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

double b,c;
inline double f(double x){
  return (x*x + b*x + c)/sin(x);
}

double ternary_search(){
  double eps = 1e-9;
  double l = eps, r = (M_PI / 2) - eps;
  while(r-l > eps){
    double m1 = l + (r-l)/3;
    double m2 = r - (r-l)/3;
    if(f(m1) > f(m2))
      l = m1;
    else
      r = m2;
  }
  return f(l);
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    cin>>b>>c;
    cout << fixed << setprecision(9) << ternary_search() << endl;
  }
  return 0;
}
