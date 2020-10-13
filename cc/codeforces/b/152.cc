#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
const int INF = 1e9 + 5;

int32_t main(int argc, char const *argv[]){
  fastIO;
  ll n, m,x,y;
  cin>>n>>m>>x>>y;
  ll count = 0;
  int k; cin>>k;
  /*REP(i,k){
    int dx,dy;
    cin>>dx>>dy;
    int xx,yy;
    if(dx > 0)
      xx = (n-x) / dx;
    else if(dx < 0)
      xx = (1-x) / (dx);
    else
     xx = INF;

    if(dy > 0)
      yy = (m-y) / dy;
    else if(dy < 0)
      yy = (1-y) / (dy);
    else
      yy = INF;
    db(count);
    if(xx > yy){
      x = dx * yy + x;
      y = dy * yy + y;
      count += yy;
    }
    else{
      x = dx * xx + x;
      y = dy * xx + y;
      count += xx;
    }
  }*/
  auto onField = [&](ll xx, ll yy){
    return (0 < xx && xx <= n && 0 < yy && yy <= m);
  };
  // binary search
  REP(i,k){
    ll dx,dy;
    cin>>dx>>dy;
    for(ll cof = 1100000000; cof; cof /= 2){
      while(onField(x + cof * dx, y + cof * dy)){
        x = x + cof * dx;
        y = y + cof * dy;
        count += cof;
      }
    }
  }
  cout << count << endl;
  return 0;
}
