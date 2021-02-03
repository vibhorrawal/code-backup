#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define REP(i,n) for(auto i=0;i<(n);i++)
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

struct Point {
  int x, y;
  void read(){
    cin>>x>>y;
  }
};

int main(){
  fastIO;
  int n;
  cin>>n;
  vector<Point> p(n);
  REP(i,n) p[i].read();
  unordered_map<int,int> Xmap, Ymap;
  map<pair<int,int>, int> XY;
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += Xmap[p[i].x]++ + Ymap[p[i].y]++ - XY[{p[i].x, p[i].y}]++;
  }
  cout << ans << endl;
}
